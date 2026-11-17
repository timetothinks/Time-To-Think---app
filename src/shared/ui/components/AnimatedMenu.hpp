#ifndef ANIMATED_MENU_HPP
#define ANIMATED_MENU_HPP

#include "raylib.h"
#include <string>
#include <functional>
#include "shared/ui/Ui.hpp"

#include "shared/ui/button/ButtonCustom.hpp"
#include "shared/ui/Canvas.hpp"
#include "shared/ui/utils/AnimationsUtils.hpp"
#include "shared/ui/utils/IconUtils.hpp"

/**
 * @class AnimatedMenu
 * @brief Implementa un menu interactivo con contenido desplegable.
 *
 * @details
 * AnimatedMenu permite mostrar y ocultar un área de contenido
 * mediante un botón desencadenante. Integra un Button y un Canvas
 * para gestionar la interacción y la presentación de sus elementos.
 *
 * @author Time To Think - ELC
 * @version 0.1.0
 *
 * @see CustomButton
 * @see Canvas
 * @see Ui
 */

class AnimatedMenu : public Ui {

private:
    /// @brief componente interno para activar el menu
    ButtonCustom* triggerButton;
    /// @brief componente interno para dibujar el fondo del menu
    Canvas* contentCanvas;

    /// @brief define si el Canvas, fondo del menu se dibuja
    bool isShow = false;
    /// @brief define si el Canvas/menu esta bloqueado
    /// @details 
    /// cuando el cursor del raton sale del boton o canvas se cierra, pero si
    /// isLocked es true se queda abierto independientemente del raton
    bool isLocked = false;
    
    /// @brief ancho del boton que activa el menu
    float buttonWidth;
    /// @brief alto del boton que activa el menu
    float buttonHeight;
    /// @brief ancho el fondo @ref AnimatedMenu::contentCanvas
    float targetWidth;
    /// @brief alto del fondo @ref AnimatedMenu::contentCanvas
    float targetHeight;

    /// @brief ancho actual del fondo del menu @ref AnimatedMenu::contentCanvas
    float currentWidth = 0.0f;
    /// @brief velocidad de la animacion de cierre y apertura del menu
    float animationSpeed;

    /// @brief icono que representa el estado de @ref AnimatedMenu::isLocked
    /// @details si @ref AnimatedMenu::isLocked es true, el icono esta cerrado, si es false
    /// el icono esta abierto, como un candado
    const char* locker = Icons::LOCK;

public:
    /// @brief constructor @ref AnimatedMenu, construye los objetos internos
    /// Canvas y CustomButton
    /// @param btnW ancho del boton que activa el menu
    /// @param btnH alto del boton que activa el menu
    /// @param width ancho del menu
    /// @param height alto del menu
    /// @param colorLeft color desde la izquierda al menu
    /// @param colorRigth color desde la derecha del menu
    /// @param triggerColor color del boton que activa el menu
    /// @param title titulo del menu
    /// @param drawContent funcion Lambda que define que se dibujara dentro del menu
    /// @param onUseCallback funcion Lambda que define que pasara al clickear el boton que activa el menu
    /// @param onMousePassCallback funcion Lambda que define que pasara al pasar el raton por el boton que activa el menu
    /// @param onMouseOutCallback funcion Lambda que define que pasara al salir el raton del boton que activa el menu
    AnimatedMenu(
        float btnW, float btnH, float width, float height, 
        Color colorLeft, Color colorRigth, Color triggerColor, std::string title, 
        std::function<void(const Rectangle&)> drawContent, 
        std::function<void()> onUseCallback = nullptr,
        std::function<void()> onMousePassCallback = nullptr,
        std::function<void()> onMouseOutCallback = nullptr)
        {
        this->buttonWidth = btnW;
        this->buttonHeight = btnH;
        this->targetWidth = width;
        this->targetHeight = height;
        animationSpeed = 1500.0f;

        triggerButton = new ButtonCustom(0, 0, btnW, btnH, triggerColor,
            [this, onMousePassCallback]() { 
                this->isShow = true; 
                if(onMousePassCallback) onMousePassCallback();
            },
            [this, onMouseOutCallback]() {
                this->isShow = false; 
                if(onMouseOutCallback) onMouseOutCallback();
            },
            [this, onUseCallback]() { 
                this->isLocked = !this->isLocked;
                if(onUseCallback) onUseCallback();
                locker = (this->isLocked) ? Icons::UNLOCK : Icons::LOCK;
            }
        );

        contentCanvas = new Canvas(0, 0, 0, height,
        [colorLeft, colorRigth, title, drawContent, this](const Rectangle& bounds) {
            DrawTextEx(
                ScreenManager::Instance().getFontJetbrains(),
                title.c_str(),
                Vector2{bounds.x + 20.0f, bounds.y - buttonHeight + 10.0f}, 
                24.0f, 2.0f, BLACK
            );
            Icons::drawIcon(
                Icons::MENU_SIDEBAR,
                bounds.x + 3.0f, bounds.y - buttonHeight/2,
                32, BLACK
            );
            Icons::drawIcon(
                locker,
                bounds.x + buttonWidth, 
                bounds.y - buttonHeight/2,
                32, BLACK
            );
            DrawRectangleLinesEx(
                triggerButton->getBounds(), 2.0f, BLACK
            );
            if(bounds.width > 10.0f) {
                DrawRectangleGradientH(
                    static_cast<int>(bounds.x),
                    static_cast<int>(bounds.y), 
                    static_cast<int>(bounds.width), 
                    static_cast<int>(bounds.height),
                    colorLeft, 
                    colorRigth
                );
                DrawRectangleLinesEx(bounds, 2.0, DARKGRAY);
                if(drawContent) drawContent(bounds);
            }
        },
            [this, onMousePassCallback, onMouseOutCallback](Rectangle& bounds) {
                Vector2 mousePos = GetMousePosition();
                this->isShow = CheckCollisionPointRec(mousePos, bounds) || CheckCollisionPointRec(mousePos, triggerButton->getBounds());
                bool canOpen = (this->isLocked || this->isShow);
                AnimationsUtils::SlideWidth(bounds, this->targetWidth, this->animationSpeed, canOpen);
                
                if(this->isShow) if(onMousePassCallback) onMousePassCallback();
                if(!(this->isShow || this->isLocked)) if(onMouseOutCallback) onMouseOutCallback();

                this->currentWidth = bounds.width;
            }
        );
    }

    /// @brief deconstructor 
    ~AnimatedMenu() {
        delete triggerButton;
        delete contentCanvas;
    }

    /// @brief posiciona los objetos que componen a @ref AnimatedMenu
    /// @param x posicion x en la pantalla
    /// @param y posicion y en la pantalla
    /// @note sobrescribe @ref Ui::setPosition()
    void setPosition(float x, float y) override {
        triggerButton->setPosition(x, y);
        contentCanvas->setPosition(x, y + this->buttonHeight);
    }

    /// @brief actualiza la logica del menu y sus componentes
    /// @details actualiza la logica de los componentes internos de Button y Canvas
    /// @note sobrescribe @ref Ui::logic()
    void logic() override {
        triggerButton->logic();
        contentCanvas->logic();
    }

    /// @brief dibuja el menu
    /// @details dibuja los componentes internos Button y Canvas
    /// @note sobrescribe @ref Ui::draw()
    void draw() override {
        triggerButton->draw();
        contentCanvas->draw();
    }

    /// @brief cambia el de AnimatedMenu::isLocked por su contrario
    void toggleMenuLocked() { this->isLocked = !this->isLocked; }
    /// @brief obtiene el estado de bloqueo del menu
    /// @return bool
    bool isMenuLocked() {return this->isLocked;}

    /// @brief obtiene el estado de visibilidad del menu
    /// @return bool
    bool isMenuShow() {return this->isShow;}

    /// @brief obtiene los limites del Canvas asociado al menu
    /// @return Rectangle 
    /// @see Canvas::getBounds()
    Rectangle getCanvasBounds() { return this->contentCanvas->getBounds(); }

};

#endif
