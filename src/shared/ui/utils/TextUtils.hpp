#ifndef TEXT_UTILS
#define TEXT_UTILS

#include "raylib.h"
#include <string>

#include "core/ScreenManager.hpp"

/**
 * @namespace TextUtils
 * @brief Utils para funciones de texto dentro de la pantalla
 */

namespace TextUtils {

    /// @brief obtiene mediante un Vector2 la posicion donde deberia de estar un texto para 
    /// estar centrado dentro de un rectagulo
    /// @param text texto que se quiere centrar
    /// @param container rectangulo donde se quiere centrar
    /// @param fontSize tamaño de la fuente de texto
    /// @param space espaciado de texto
    /// @param font fuente usada en el texto
    /// @return Vector2
    inline Vector2 getCenterInRect(const std::string& text, Rectangle container, 
        float fontSize, float space, Font font) 
        {
        Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, space);

        Vector2 textPos;
        textPos.x = container.x + (container.width / 2.0f) - (textSize.x / 2.0f);
        textPos.y = container.y + (container.height / 2.0f) - (textSize.y / 2.0f); 
        
        return textPos;
    }

    /// @brief dibuja un centro centrado mediante la funcion @ref TextUtils::getCenterInRect()
    /// @param text texto que se quiere dibujar centrado
    /// @param container rectangulo donde se dibujara
    /// @param fontSize tamaño de la fuente de texto
    /// @param spacing espaciado de texto
    /// @param color color de texto
    /// @param font fuente de texto
    inline void DrawCenteredInRec(const std::string& text, Rectangle container,
        float fontSize, float spacing, Color color, Font font) 
        {
        Vector2 textPos = getCenterInRect(text, container, fontSize, spacing, font);
        DrawTextEx(font, text.c_str(), textPos, fontSize, spacing, color);
    }
     
    inline Vector2 getHorizontalCenter(const std::string& text, 
        float centerX, float yPosition, float fontSize, float spacing, Font font = GetFontDefault()) 
        {
        Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, spacing);
        return Vector2{ centerX - (textSize.x / 2.0f), yPosition };
    }

}

#endif