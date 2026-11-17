#ifndef POPUP
#define POPUP

#include "raylib.h"
#include <string>

#include "core/ScreenManager.hpp"
#include "shared/ui/Ui.hpp"

#include "shared/ui/utils/TextUtils.hpp"

class Popup : public Ui {

private:
    Rectangle box;
    Color color;
    std::string text;

    bool active;
    float lifetime;
    float time;

public:
    Popup(std::string text) 
    : text(text), active(false), lifetime(0.0f), time(0.0f),
     box({
        ScreenManager::Instance().getWidth(50.0f),
        ScreenManager::Instance().getHeight(90.0f),
        300.0f,
        30.0f
    }), color(Color{50, 50, 50, 128}) {} 
    
    void send(float duration) {
        active = true;
        lifetime = duration;
        time = 0.0f;
    }

    void logic() override {
        if(!active) return;

        time += GetFrameTime();
        if(time >= lifetime) active = false;
    }

    void draw() override {
        if(!active) return;

         DrawRectangleRec(box, color);
         DrawRectangleLinesEx(box, 0.5, BLACK);
        
        TextUtils::DrawCenteredInRec(text, box, 10.0f, 0.8f, BLACK, GetFontDefault());
    }

    bool isActive() { return active; }

    void setText(std::string newText) {
        if(newText == this->text) return;
        this->text = newText;
    }

    void setPosition(float x, float y) override {
        box.x = x;
        box.y = y;
    }
};

#endif