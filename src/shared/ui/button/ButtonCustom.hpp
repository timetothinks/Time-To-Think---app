#ifndef BUTTON_CUSTOM
#define BUTTON_CUSTOM

#include "raylib.h"
#include <functional>

#include "shared/ui/Ui.hpp"

/**
 * @class ButtonCustom
 * @brief Implementa botones customizables
 *
 * @details
 * permite crear objetos que al clickear/usar haga cualquier cosa
 * permite mas libertad que @ref Button
 * 
 * @author Time To Think - ELC
 * @version 0.1.0
 *
 * @see Ui
 */

class ButtonCustom : public Ui {
private:
    /// @brief limites del CustomButtom
    Rectangle bounds;
    /// @brief color del boton
    Color color;
    /// @brief almacena el estado de cuando el mouse pasa por encima del CustomButton
    bool isMouseOver;

    /// @brief funcion lambda que define que pasa al pasar el mouse por encima del boton
    std::function<void()> onMousePassCallback;
    /// @brief funcion lambda que define que pasa el salir el mouse del boton
    std::function<void()> onMouseOutCallback;
    /// @brief funcion lambda que define que pasa al clickear/usar el boton
    std::function<void()> onUseCallback;

public:
    /// @brief constructor de @ref ButtonCustom
    /// @param x posicion x en pantalla
    /// @param y posicion y en pantalla
    /// @param width ancho del boton
    /// @param height alto del boton
    /// @param color color
    /// @param onMousePass funcion lambda que define que pasa al pasar el mouse por encima del boton
    /// @param onMouseOut funcion lambda que define que pasa el salir el mouse del boton
    /// @param onUse funcion lambda que define que pasa al clickear/usar el boton
    ButtonCustom(float x, float y, float width, float height, Color color,
    std::function<void()> onMousePass, std::function<void()> onMouseOut, std::function<void()> onUse)
        : bounds({x, y, width, height}), color(color), isMouseOver(false),
        onMousePassCallback(onMousePass), onMouseOutCallback(onMouseOut), onUseCallback(onUse) {}

    /// @brief logica que actualiza el boton
    /// @note sobrescribe @ref Ui::logic()
    void logic() override {
        Vector2 mousePos = GetMousePosition();
        bool isMouseOverNow = CheckCollisionPointRec(mousePos, bounds);

        if(isMouseOverNow) {
            if(!isMouseOver) {
                if(onMousePassCallback) onMousePassCallback();
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if(onUseCallback) onUseCallback();
            }
        } else {
            if(isMouseOver) {
                onMouseOutCallback();
            }
        }
        isMouseOver = isMouseOverNow;
    }

    /// @brief dibuja el boton en pantalla
    /// @note sobrescribe @ref Ui::draw()
    void draw() override {
        DrawRectangleRec(bounds, color);
    }

    /// @brief posiciona en pantalla el boton
    /// @param x posicion x en pantalla
    /// @param y posicion y en pantalla
    /// @note sobrescribe @ref Ui::setPosition()
    void setPosition(float x, float y) override {
        bounds.x = x;
        bounds.y = y;
    }

    /// @brief getter de @ref Button::bounds
    /// @return Rectangle
    Rectangle getBounds() {return this->bounds;}
};

#endif