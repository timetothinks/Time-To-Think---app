#include "raylib.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include "IntroScreen.hpp"

#include "shared/ui/button/Button.hpp"
#include "shared/ui/utils/TextUtils.hpp"
#include "core/ScreenManager.hpp"

void IntroScreen::init() {
    time = 0.0f;
    introDuration = 5.2f;
    logoAlpha = 0.0f;

    squareSize = 0.0f;
    dynamicR = 0;
    dynamicG = 0;
    dynamicB = 0;

    backgroundB = 20;
    backgroundG = 15;
    backgroundR = 15;
}

void IntroScreen::resizeScreen() {}

void IntroScreen::draw() {  
    ClearBackground(Color{backgroundR, backgroundG, backgroundB, 255});

    float height = GetScreenHeight();
    float width = GetScreenWidth();
    DrawText(
        "TIME TO THINK", 
        width / 2 - 120, 
        height / 2 - 15,
        30, Fade(RAYWHITE, (float)logoAlpha/255.0f));
    DrawText(
        "              presenta \n\n"
        "  Salvador Rafael Gomez Parra \n"
        "Roberto Jouse Sepulveda Naranjo", 
        width / 2 - 80, 
        height / 2 + 30,
        10, Fade(GRAY, (float)logoAlpha/255.0f));
    DrawText(
        "[presiona [espacio] para omitir]", 
        20, 
        height - 40,
        17, DARKGRAY);

    float size = 100.0f + squareSize;
    Rectangle rect = {width/2, (height/2), size, size};
    Vector2 origin = {size/2, size/2};
    Color color = {dynamicR, dynamicG, dynamicB, 255};
    //BeginBlendMode(BLEND_ADDITIVE);
    DrawRectanglePro(rect, origin, 0.0f,
         Fade(color, 0.15f * ((float)logoAlpha/255.0f)));
    //EndBlendMode();
    //DrawRectangleLinesEx(rect, 2, Fade(DARKGRAY, 0.3f * ((float)logoAlpha/255.0f)));
}

void IntroScreen::logic() {
    time += GetFrameTime();
    logoAlpha += alphaOperator;
    bool backgroundFade = false;

    if(logoAlpha >= 255) {
        logoAlpha = 255;
        alphaOperator = -2.0f;

    } else if (logoAlpha <= 0.0f) {
        logoAlpha = 0.0f;
        alphaOperator = 0.0f;
        backgroundB = std::min(255.0f, backgroundB + time * 2.0f);
        backgroundG = std::min(255.0f, backgroundG + time * 2.0f);
        backgroundR = std::min(255.0f, backgroundR + time * 2.0f);
    }

    if(time >= introDuration || IsKeyPressed(KEY_SPACE)) {
        SM.changeScreen("main_menu");
    }

    squareSize = sinf(time * 3.0f) * 15.0f;

    float timeBase = time * 6.0f;

    float rWave = sinf(timeBase) * 0.5f + 0.5f;
    float gWave = sinf(timeBase + 2.0f) * 0.5f + 0.5f;
    float bWave = sinf(timeBase + 4.0f) * 0.5f + 0.5f;

    dynamicR = (unsigned char)(rWave * 255);
    dynamicG = (unsigned char)(gWave * 255);
    dynamicB = (unsigned char)(bWave * 255);
}

void IntroScreen::cleaner() {}