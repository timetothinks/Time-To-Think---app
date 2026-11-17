#ifndef LESSON
#define LESSON

#include "raylib.h"
#include <unordered_map>
#include <variant>
#include <vector>

#include "core/ScreenManager.hpp"
#include "LessonElement.hpp"
#include "shared/ui/button/Button.hpp"

/**
 * @class Lesson
 * @brief administra el ciclo de una leccion
 * 
 * @author Time To Think - ELC
 * @version 0.1.0
 */

/// @brief guarda todos los elementos de una leccion
/// @see LessonElement 
using Element = std::variant<
    LessonElement::Line,
    LessonElement::Square,
    LessonElement::SquareLines,
    LessonElement::Circle,
    LessonElement::Text,
    LessonElement::Image,
    LessonElement::ButtonElement
>;

class Lesson {
private:
    /// @brief frame actual de la leccion
    int frame = 0; 
    /// @brief guarda todo el contenido de una leccion por cada frame
    //// @see LessonElement
    std::unordered_map<int, std::vector<Element>> frameUiContent;

public:
    Lesson() = default;

    /// @brief agrega un nuevo frame a la leccion
    /// @param content contenido que tendra dentro el frame
    /// @see LessonElement
    void addFrame(const std::vector<Element>& content) {
        int index = frameUiContent.size();
        frameUiContent[index] = content;
    }

    /// @brief Dibuja todo el contenido de un frame
    /// @param frame frame a dibujar
    void drawFrame(int frame) {
        auto it = frameUiContent.find(frame);

        if(it == frameUiContent.end()) return;

        for(const auto& element : it->second) {
            std::visit([](const auto& element) {

            using T = std::decay_t<decltype(element)>;

            if constexpr (std::is_same_v<T, LessonElement::Text>) {
                DrawTextEx(
                    element.fontType,
                    element.text.c_str(),
                    Vector2{element.position.x, element.position.y},
                    element.fontSize,
                    2.0f,
                    element.color
                );

            } else if constexpr (std::is_same_v<T, LessonElement::Line>) {
                DrawLineEx(
                    element.start,
                    element.end,
                    element.thickness,
                    element.color
                );

            } else if constexpr (std::is_same_v<T, LessonElement::Circle>) {
                DrawCircleV(
                    element.position,
                    element.radius,
                    element.color
                );
            } else if constexpr (std::is_same_v<T, LessonElement::Square>) {
                DrawRectangle(
                    element.x,
                    element.y,
                    element.width,
                    element.height,
                    element.color
                );
            } else if constexpr (std::is_same_v<T, LessonElement::Image>) {
                DrawTextureEx(
                    element.txt,
                    Vector2{(element.x), (element.y)},
                    element.rotation,
                    element.scale,
                    element.color
                );
            } else if constexpr (std::is_same_v<T, LessonElement::SquareLines>) {
                DrawRectangleLinesEx(
                    Rectangle{element.x, element.y, element.width, element.height},
                    element.thickness,
                    element.color
                );
            } else if constexpr (std::is_same_v<T, LessonElement::ButtonElement>) {
                element->draw();
            }

        }, element);
        }
    }

    /// @brief procesa la logica de todo el contenido del frame
    /// @param frame frame a procesar
    void logicFrame(int frame) {
    auto it = frameUiContent.find(frame);

    if(it == frameUiContent.end()) return;
    for(auto& element : it->second) {
        std::visit([](auto& element) {
            using T = std::decay_t<decltype(element)>;

            if constexpr (std::is_same_v<T, LessonElement::ButtonElement>) {
                element->logic();
            }
        }, element);
    }
    }

    /// @brief avanza de forma segura al siguiente frame
    void nextFrame() {
        if(frame + 1 < static_cast<int>(this->frameUiContent.size())) frame++;
    }

    /// @brief vuelve de forma segura al anterior frame
    void previousFrame() {
        if(frame > 0) frame--;
    }

    /// @brief dibuja el frame actual
    void draw() {
        drawFrame(frame);
    }

    /// @brief procesa la logica del frame actual
    void logic() {
        logicFrame(frame);
    }

    /// @brief obtiene el frame actual
    /// @return int
    int getCurrentFrame() const { return frame; }

    /// @brief obtiene todos los frames que hay
    /// @return int
    int getFrameCount() const { return static_cast<int>(frameUiContent.size()); }

};

#endif