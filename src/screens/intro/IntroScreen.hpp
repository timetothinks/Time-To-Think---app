#ifndef INTRO_SCREEN
#define INTRO_SCREEN

#include <vector>

#include "screens/ScreenTemplate.hpp"
#include "shared/ui/Ui.hpp"

class Button;

class IntroScreen : public ScreenTemplate {

private:
    float time;
    float introDuration;
    int logoAlpha;
    float alphaOperator = 2.0f;

    float squareSize;
    unsigned char dynamicR, dynamicG, dynamicB;
    unsigned char backgroundR, backgroundG, backgroundB;

public:
    IntroScreen(ScreenManager& sm) : ScreenTemplate(sm) {}

    void init() override;
    void draw() override;
    void logic() override;
    void cleaner() override;

    void resizeScreen() override;
};

#endif