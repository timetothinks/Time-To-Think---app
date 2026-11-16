#ifndef SCREEN_TEMPLATE 
#define SCREEN_TEMPLATE 

/**
 * @class ScreenTemplate
 * @brief interfaz para pantallas para definir su contrato con los metodos necesarios
 * 
 * @author Time To Think - ELC
 * @version 0.1.0
 */

class ScreenManager;

class ScreenTemplate {
protected:
    /// @brief instancia inyectada de cada pantalla de ScreenManager
    ScreenManager& SM;

public:
    /// @brief constructor de ScreenTemplate
    /// @param sm inyeccion de la instancia ScreenManager para toda clase que hereda ScreenTemplate
    ScreenTemplate(ScreenManager& sm) : SM(sm) {}

    /**
     * @brief gestiona en esta parte la logica de inicializacion de la pantalla que hereda ScreenTemplate
     * 
     * @details 
     * ejecuta el metodo ScreenTemplate::init() de la pantalla
     * almacenada en @ref ScreenManager::currentScreen
     */
    virtual void init() = 0;

    /**
     * @brief gestiona en esta parte la logica de dibujado de la pantalla que hereda ScreenTemplate
     * 
     * @details 
     * ejecuta el metodo ScreenTemplate::draw() de la pantalla
     * almacenada en @ref ScreenManager::currentScreen
     */
    virtual void draw() = 0;

    /**
     * @brief gestiona en esta parte la logica de la pantalla que hereda ScreenTemplate
     * 
     * @details 
     * ejecuta el metodo ScreenTemplate::logic() de la pantalla
     * almacenada en @ref ScreenManager::currentScreen
     */
    virtual void logic() = 0;

    /**
     * @brief Se encarga de limpiar todos los elementos cargados
     * para la pantalla actual, como instancias de @ref Ui
     * 
     * @details 
     * ejecuta el metodo ScreenTemplate::cleaner() de la pantalla
     * almacenada en @ref ScreenManager::currentScreen para poder
     * pasar a la siguiente pantalla de forma segura
     * 
     * @see ScreenManager::changeScreenPending()
     */
    virtual void cleaner() = 0;

    /**
     * @brief Define aqui la posicion de todos los elementos @ref Ui
     * que hay registrados en la pantalla
     * 
     * @see Ui::setPosition()
     */
    virtual void resizeScreen() = 0;

    /**
     * @brief Destructor virtual de ScreenTemplate
     */
    virtual ~ScreenTemplate() = default;
};

#endif