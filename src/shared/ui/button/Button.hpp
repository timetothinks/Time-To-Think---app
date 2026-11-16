#ifndef BUTTON
#define BUTTON

#include "raylib.h"
#include <functional>
#include "string"

#include "shared/ui/Ui.hpp"
#include "shared/ui/utils/TextUtils.hpp"

/**
 * @class Button
 * @brief Implementa botones 
 *
 * @details
 * permite crear objetos que al clickear/usar haga cualquier cosa
 *
 * @author Time To Think - ELC
 * @version 0.1.0
 *
 * @see Ui
 */

class Button : public Ui {
private:
    /// @brief limites del boton
    Rectangle bounds;
    /// @brief titulo del boton
    std::string title;
    /// @brief color del boton
    Color color;
    /// @brief almacena el color original del boton para cambios de color
    Color colorBase;

    /// @brief funcion lambda que define que pasa al usar el boton
    std::function<void()> onUseCallback;

    /// @brief tamaño del boton
    float fontSize;
    /// @brief tipo de fuente de texto del boton
    Font fontType;

public:
    /// @brief constructor de @ref Button
    /// @param x posicion x en pantalla
    /// @param y posicion y en pantalla
    /// @param width ancho del boton
    /// @param height alto del boton
    /// @param title titulo
    /// @param color color
    /// @param onUse funcion lambda al clickear/usar el boton
    /// @param fontSize tamaño del boton
    /// @param fontType tipo de fuente de texto del boton
    Button(float x, float y, float width, float height, std::string title, Color color, std::function<void()> onUse, 
    float fontSize = 12.0f, Font fontType = ScreenManager::Instance().getFontPressStar())
    : bounds({x, y, width, height}), title(title), color(color), colorBase(color), onUseCallback(onUse),
    fontSize(fontSize), fontType(fontType) {}

    /// @brief logica que actualiza el boton
    /// @note sobrescribe @ref Ui::logic()
    void logic() override {
        Vector2 mousePos = GetMousePosition();

        if(CheckCollisionPointRec(mousePos, bounds)) {
            color = DARKGRAY;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if(onUseCallback) {
                    onUseCallback();
                }
            }
        } else {
            color = this->colorBase;
        }
    }

    /// @brief dibuja el boton en pantalla
    /// @note sobrescribe @ref Ui::draw()
    void draw() override {
        DrawRectangleRec(bounds, color);
        DrawRectangleLinesEx(bounds, 0.5, BLACK);

        TextUtils::DrawCenteredInRec(title, bounds, this->fontSize, 1.0f, BLACK, this->fontType);
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

    /// @brief setter para el color el boton
    /// @param color 
    void setColor(Color color) { this->color = color; }
};

#endif