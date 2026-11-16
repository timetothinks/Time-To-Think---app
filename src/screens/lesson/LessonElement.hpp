#ifndef LESSON_ELEMENT
#define LESSON_ELEMENT

#include "raylib.h"
#include <string>

/**
 * @namespace LessonElement
 * @brief simplica todos los elemento que una leccion puede tener
 * 
 * @author Time To Think - ELC
 * @version 0.1.0
 */

class Button;

#include "core/ScreenManager.hpp"

namespace LessonElement {

    /// @struct Square
    /// @brief representa un rectangulo
    struct Square {
        float x;
        float y;
        float width;
        float height;
        Color color;
    };

    /// @struct SquareLines
    /// @brief representa las lineas/bordes de un rectangulo
    struct SquareLines {
        float x;
        float y;
        float width;
        float height;
        Color color = WHITE;
        float thickness = 1.0f;
    };

    /// @brief Line
    /// @brief representa una linea del punto a-b
    struct Line {
        Vector2 start;
        Vector2 end;
        Color color;
        float thickness;
    };

    /// @struct Circle
    /// @brief representa un circulo
    struct Circle {
        Vector2 position;
        float radius;
        Color color;
    };

    /// @struct Text
    /// @brief representa texto
    struct Text {
        std::string text;
        Vector2 position;
        float fontSize;
        Color color = BLACK;
        Font fontType = ScreenManager::Instance().getFontJetbrains();
    };

    /// @struct Image
    /// @brief representa una imagen
    struct Image {
        Texture2D txt;
        float x;
        float y;
        Color color = WHITE;
        float scale = 1.0f;
        float rotation = 0.0f;
    };
    
    /// @struct Button
    /// @brief representa un Button
    /// @see Button
    using ButtonElement = ::Button*;
}

#endif