#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

/**
 * @class ScreenManager
 * @brief administra las pantallas, su ciclo de vida y su logica general
 * 
 * @author Time To Think - ELC
 * @version 0.1.0
 */

#include "raylib.h"

#include <unordered_map>
#include <string>
#include <functional>

class ScreenTemplate;

class ScreenManager {
private:
    /// @brief fuente de texto para titulos
    Font titleFont;
    /// @brief fuente de textos para titulos
    Font titleTwoFont;
    /// @brief fuente de texto para textos casuales
    Font casualFont;
    /// @brief fuente de texto para botones
    Font buttonFont;
    /// @brief fuente de texto para iconos
    Font iconsFont;
    /// @brief guarda todas los objetos Texture2D para acceder rapidamente a ellos
    std::unordered_map<std::string, Texture2D> textures;

    /// @brief pantalla actual que gestiona ScreenManager
    ScreenTemplate* currentScreen;
    /// @brief siguiente pantalla en cola
    std::string nextScreenName;
    /// @brief factory de Screens asociativo por clave - valor
    std::unordered_map<std::string, std::function<ScreenTemplate*()>> screenFactory;

    /**
     * @brief constructor de ScreenManager
     * 
     * @details
     * Se encuentra privado para evitar que se instancie directamente
     * ya que la clase ScreenManager se administra mediante el patron Singleton.
     */
    ScreenManager();

public:
    ~ScreenManager();
    /**
     * @brief Singleton de ScreenManager
     * 
     * @details
     * La clase ScreenManager utiliza el patron Singleton para garantizar
     * que exista una sola instancia de la misma
     * 
     * @return ScreenManager
     */
    static ScreenManager& Instance();
    /** 
    * @brief Carga los recursos en assets/ 
    * Fonts, imagenes, etcetera
    * 
    * @return void
    */
    void loadResources();

    /** 
    * @brief Descarga los recursos de assets/ cargados en @ref ScreenManager::loadResources()
    * 
    * 
    * @return void
    */
    void unloadResources();

    /**
     * @brief obtiene la fuente de texto Black-Regular como una variable Font
     * 
     * @return Font
     */
    Font getFontRegular();

    /**
     * @brief obtiene la fuente de texto JetBrainsMono-italic como una variable Font
     * 
     * @return Font
     */
    Font getFontJetbrains();

    /**
     * @brief obtiene la fuente de texto PressStar2P-regular como una variable Font
     * 
     * @return Font
     */
    Font getFontPressStar();

    /**
     * @brief obtiene la fuente de texto remixicons como una variable Font
     * 
     * @return Font
     */
    Font getFontIcons();

    /// @brief obtiene la fuente de texto anton como una variable Font
    /// @return Font
    Font getFontAnton();

    /// @brief obtiene una imagen .svg para retornarla como un objeto Image
    /// @param directory direccion de la imagen
    /// @return Image
    Texture2D getTexture(const std::string& key);

    /**
     * @brief Actualiza la pantalla actual
     * 
     * @details
     * busca cual es la pantalla actual segun @ref ScreenManager::currentScreen 
     * para ejecutar su metodo @ref ScreenTemplate::update()
     * 
     * @return void
     */
    void update();
    /**
     * @brief Dibuja la pantalla actual
     * 
     * @details
     * busca cual es la pantalla actual segun @ref ScreenManager::currentScreen 
     * para ejecutar su metodo @ref ScreenTemplate::draw()
     * 
     * @return void
     */
    void draw();

    /**
     * @brief Registra una nueva pantalla dentro de @ref ScreenManager::screenFactory
     * 
     * @details
     * Las registra con id de texto
     * se guardan funciones lambda que retornan una instancia de la pantalla
     * asi se llama por nombre y se referencia una instancia
     * 
     * @param name id con el cual se guardara la referencia a la pantalla segun su funcion lambda
     * @param creator funcion lambda que crea una instancia de la pantalla guardada para referenciarla
     * 
     * @return void
     */
    void registerScreen(const std::string& name, std::function<ScreenTemplate*()> creator);
    
    /**
     * @brief Guarda la pantalla en @ref ScreenManager::nextScreenName para ponerla en cola
     * 
     * @details
     * Cambia de pantalla por referencia de nombre registrado en el
     * factory @ref ScreenManager::screenFactory
     * 
     * @warning puede generar un TRACE_ERROR si no existe en @ref ScreenManager::screenFactory una
     * pantalla con dicho id
     * 
     * @param name id que busca en ScreenManager::screenFactory para buscar una pantalla
     * 
     * @return void
     */
    void changeScreen(const std::string& name);

    /**
     * @brief Cambia de pantalla remplazando la actual por @ref ScreenManager::nextScreenName
     * 
     * @details
     * Esta funcion esta hecha para evitar problemas de memoria
     * en general limpia la memoria de la anterior pantalla para 
     * introducir una nueva de forma limpia
     * 
     * Primero es necesario usar @ref ScreenManager::changeScreen() para
     * validar la nueva pantalla
     */
    void changeScreenPending();

    /**
     * @brief retorna el porcentaje de el ancho actual de la pantalla
     * 
     * @param percentage porcentaje al que quieres apuntar en la pantalla actual
     * 
     * @return float
     */
    float getWidth(float percentage);

    /**
     * @brief retorna el porcentaje de el alto actual de la pantalla
     * 
     * @param percentage porcentaje al que quieres apuntar en la pantalla actual
     * 
     * @return float
     */
    float getHeight(float percentage);
};

#endif