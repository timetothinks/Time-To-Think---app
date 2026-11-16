#ifndef START_SCREEN
#define START_SCREEN

#include <string>

#include "screens/ScreenTemplate.hpp"

class Lesson;
class Button;

class StartScreen : public ScreenTemplate {

private:
    Color backgroundColor = BLACK;
    float transition = 0.0f;
    Color transitionColor = RED;
    bool startTransition = false;
    
    Lesson* lesson;
    Button* addFrame;
    Button* quitFrame;

    Button* questionOne;
    Button* questionTwo;
    Button* questionThree;
    Button* questionFour;

    Button* questionFive;
    Button* questionSix;
    Button* questionSeven;
    Button* questionFinal;

    std::string ansewerOne = "";

    void startColorTransition(Color initialColor) {
        transitionColor = initialColor;
        transition = 0.0f;
        startTransition = true;
    }

public:
    StartScreen(ScreenManager& sm) : ScreenTemplate(sm) {}

    void init() override;
    void draw() override;
    void logic() override;
    void cleaner() override;

    void resizeScreen() override;
};

#endif