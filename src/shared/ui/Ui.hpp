#ifndef UI
#define UI

/**
 * @class Ui
 * 
 * @brief Interfaz para los elementos UI y definir su contrato con los metodos necesarios
 */
class Ui {
protected:
    /// @brief define si el elemento es visible o no en la pantalla
    bool visible = true;

public:
    /// @brief destructor virtual de Ui
    virtual ~Ui() = default;

    /**
     * @brief Dibuja el elemeno de Ui
     */
    virtual void draw() = 0;
    /**
     * @brief Contiene la logica del elemento Ui
     */
    virtual void logic() = 0;

    /// @brief define la posicion en x,y del objeto dentro de @ref ScreenManager::currentScreen
    /// @param x coordenada x del elemento
    /// @param y coordenada y del elemento
    /// @see ScreenTemplate::resizeScreen()
    virtual void setPosition(float x, float y) = 0;
    
    /** 
     * @brief cambia el estado de @ref Ui::visible por newVisible
     * @param newVisible 
     */
    void setVisible(bool newVisible) { visible = newVisible; }

    /// @brief retorna el estado de @ref Ui::visible, osea checa si el elemento es visible o no
    /// @return bool
    bool isVisible() const { return visible; }
};

#endif