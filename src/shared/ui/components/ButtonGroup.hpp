#ifndef BUTTON_GROUP
#define BUTTON_GROUP

#include "raylib.h"
#include "shared/ui/Ui.hpp"

#include "core/ScreenManager.hpp"

#include "shared/ui/button/Button.hpp"
#include <vector>
#include <string>
#include <functional>

/**
 * @class ButtonGroup
 * @brief Implementa un conjunto de botones que se organizan y simplifican 
 *
 * @author Time To Think - ELC
 * @version 0.1.0
 *
 * @see Button
 * @see Ui
 */

class ButtonGroup : public Ui {
private:
    /// @brief conjunto de botones
    std::vector<Button*>buttons;
    /// @brief alto de los botones
    float buttonHeight;
    /// @brief ancho de los botones
    float buttonWidth;
    /// @brief espacio horizontal entre botones
    float spaceH;
    /// @brief espacio vertical entre botones
    float spaceV;

    /// @brief tamaño de la fuente de texto
    float fontSize;
    /// @brief tipo de fuente de texto
    Font fontType;

public:
    /// @brief constructor de @ref ButtonGroup
    /// @param buttonWidht ancho de los botones
    /// @param buttonHeight alto de los botones
    /// @param spaceH espacio horizontal entre botones
    /// @param spaceV espacio vertical entre botones
    /// @param fontSize tamaño de la fuente de texto
    /// @param fontType tipo de fuente de texto
    ButtonGroup(float buttonWidht, float buttonHeight, float spaceH, float spaceV,
    float fontSize = 12.0f, Font fontType = ScreenManager::Instance().getFontPressStar()) {
        this->buttonWidth = buttonWidht;
        this->buttonHeight = buttonHeight;
        this->spaceH = spaceH;
        this->spaceV = spaceV;

        this->fontSize = fontSize;
        this->fontType = fontType;
    }

    ~ButtonGroup() override {
        clear();
    }

    /// @brief agrega botones a la pantalla
    /// @param text titulo del boton
    /// @param color color del boton
    /// @param onClick funcion lambda al clickear el boton
    void addButton(const std::string& text, Color color, std::function<void()> onClick) {
        Button* newBtn = new Button(
            0, 0, 
            this->buttonWidth, this->buttonHeight, 
            text, color, onClick,
             this->fontSize, this->fontType
        );
        buttons.push_back(newBtn);
    }

    /// @brief define la posicion de los botones segun Rectangle
    /// @param container 
    void setPositionInBounds(const Rectangle& container) {
        if (buttons.empty()) return;

        int columns = static_cast<int>((container.width + this->spaceH) / (this->buttonWidth + this->spaceH));
        if (columns < 1) columns = 1; 

        float realSpacingH = this->spaceH;
        if (columns > 1) {
            realSpacingH = (container.width - (columns * this->buttonWidth)) / (columns - 1);
        }

        for (size_t i = 0; i < buttons.size(); ++i) {
            int row = i / columns;    // Fila actual (0, 1, 2...)
            int col = i % columns;    // Columna actual (0, 1... hasta columnas-1)

            float btnX = container.x + col * (this->buttonWidth + realSpacingH);
            float btnY = container.y + row * (this->buttonHeight + this->spaceV);

            if (btnY + this->buttonHeight <= container.y + container.height) {
                buttons[i]->setPosition(btnX, btnY);
                buttons[i]->setVisible(true);
            } else {
                buttons[i]->setVisible(false);
            }
        }
    }

    /// @brief posiciona el conjunto de botones en su contenedor de manera automatica
    /// @param x posicion x de todo el conjunto
    /// @param y posicion y de todo el conjunto
    void setPosition(float x, float y) override {
        Rectangle defaultContainer = {x, y, this->buttonWidth, 9999.0f};
        setPositionInBounds(defaultContainer);
    }

    /// @brief Logica interna de logica de UI
    /// @ref Ui
    void logic() override {
        if(!this->visible) return;
        
        for(auto btn : buttons) {
            if(btn->isVisible()) {
                btn->logic();
            }
        }
    }

    /// @brief logica interna de dibujado de UI
    /// @ref UI
    void draw() override {
        if(!this->visible) return;
        
        for(auto btn : buttons) {
            if(btn->isVisible()) {
                btn->draw();
            }
        }
    }

    /// @brief limpia todos los componentes usados para esta clase
    void clear() {
        for(auto btn : buttons) {
            delete btn;
        }
        buttons.clear();
    }

};

#endif