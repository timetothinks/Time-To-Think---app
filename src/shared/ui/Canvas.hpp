#ifndef CANVAS
#define CANVAS

#include "raylib.h"
#include <functional>
#include "string"

#include "Ui.hpp"

/**
 * @class Canvas
 * @brief un elemento ui que define un objeto UI totalmente personalizable mediante su logica 
 * y su dibujo, hecho para casos donde se requieren elementos de UI especificos que no se suelen
 * requerir mas de una vez en una pantalla
 * 
 */

class Canvas : public Ui {
private:
    /// @brief rectangulo del Canvas
    Rectangle bounds;

    /// @brief funcion lambda que define como se dibujara el Canvas
    std::function<void(const Rectangle&)> drawCallback;
    /// @brief funcion lambda que define como se actualiza la logica del Canvas
    std::function<void(Rectangle&)> logicCallback;

public:
    /// @brief constructor de @ref Canvas
    /// @param x posicion x en pantalla
    /// @param y posicion y en pantalla
    /// @param width alto 
    /// @param height ancho
    /// @param onDraw funcion lambda que define como se dibujara el Canvas
    /// @param onLogic funcion lambda que define como se actualiza la logica del Canvas
    Canvas(
        float x, float y, float width, float height, 
        std::function<void(const Rectangle&)> onDraw, 
        std::function<void(Rectangle&)> onLogic
    ) 
    : bounds({x, y, width, height}), drawCallback(onDraw), logicCallback(onLogic) {}

    /// @brief actualiza la logica del Canvas
    /// @note sobrescribe @ref Ui::logic()
    void logic() override { if(logicCallback) logicCallback(bounds); }
    /// @brief dibuja el Canvas
    /// @note sobrescribe @ref Ui::logic()
    void draw() override { if(drawCallback) drawCallback(bounds); }

    /// @brief posiciona el canvas en pantalla actualizando x, y
    /// @param x posicion x en pantalla
    /// @param y posicion y en pantalla
    /// @note sobrescribe @ref Ui::setPosition()
    void setPosition(float x, float y) override {
        bounds.x = x;
        bounds.y = y;
    }

    /// @brief getter de @ref Canvas::bounds
    /// @return Rectangle
    Rectangle getBounds() const { return bounds; }
    /// @brief setter de @ref Canvas::bounds
    /// @param newBound remplaza al antiguo bounds
    void setBounds(Rectangle newBound) { bounds = newBound; }

};

#endif