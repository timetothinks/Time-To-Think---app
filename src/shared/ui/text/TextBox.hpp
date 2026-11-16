#ifndef TEXT_BOX
#define TEXT_BOX

#include "raylib.h"
#include <string>

#include "shared/ui/utils/TextUtils.hpp"
#include "shared/ui/Ui.hpp"

class TextBox : public Ui {

private:
    std::string text;
    Rectangle bounds;
    Color color;
    Color background;
    float fontSize;
    float padding;

    void autoResize() {
        Font defaultFont = GetFontDefault();
        float spacing = 1.5f;
        
        // MeasureTextEx en Raylib ya soporta internamente los saltos de línea '\n'
        // Devolverá el ancho de la línea más larga y el alto total de todas las líneas combinadas
        Vector2 textSize = MeasureTextEx(defaultFont, text.c_str(), fontSize, spacing);
        
        // Le asignamos a la caja el tamaño del texto más el margen (padding) por ambos lados
        bounds.width = textSize.x + (padding * 2.0f);
        bounds.height = textSize.y + (padding * 2.0f);
    }

public:
    TextBox(float x, float y, float width, float height, std::string text, Color color, Color background, float fontSize)
     : bounds({x, y, width, height}), text(text), color(color), background(background), fontSize(fontSize), padding(15.0f) {
        if(bounds.width == 0.0f || bounds.height == 0.0f) {
            autoResize();
        }
     }

    void draw() override {
        if (background.a > 0) {
            DrawRectangleRec(bounds, background);
            DrawRectangleLinesEx(bounds, 0.7, DARKGRAY); // Línea de borde para el cuadro
        }

        TextUtils::DrawCenteredInRec(text, bounds, fontSize, 1.0f, color, GetFontDefault());
    }

    void logic() override {
        return;
    }

    void setPosition(float x, float y) override {
        bounds.x = x;
        bounds.y =y;
    }

};

#endif