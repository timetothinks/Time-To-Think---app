#ifndef MAIN_MENU_SCREEN
#define MAIN_MENU_SCREEN

#include <vector>

#include "screens/ScreenTemplate.hpp"
#include "shared/ui/Ui.hpp"

class Button;
class AnimatedMenu;
class ButtonGroup;

class MainMenuScreen : public ScreenTemplate {

private:
    std::vector<Ui*> uiElements;
    Button* demoTest;
    AnimatedMenu* sciencesMenu;
    AnimatedMenu* mathsMenu;
    AnimatedMenu* logicMenu;

    AnimatedMenu* CLMenu;
    AnimatedMenu* chemicalMenu;
    AnimatedMenu* phisycMenu;

    ButtonGroup* catalogContent;

    float catalogButtonWidth = 200.0f;
    float catalogButtonHeight = 70.0f;
    Color catalogButtonColor = Color{83, 168, 152, 255};

    float catalogMenuWidth = 700.0f;
    float catalogMenuHeight = 300.0f;

    std::vector<AnimatedMenu*> menus;

    void DrawBackgroundTexture(
    const std::string& textureName,
    float x, float y, float width, float height,
    float rotation = 0.0f,
    Color color = BLACK,
    float opacity = 0.05f
    );

    struct MenuIcon {
    AnimatedMenu* menu;
    const char* icon;
    float x;
    float y;
    };

public:
    MainMenuScreen(ScreenManager& sm) : ScreenTemplate(sm) {}

    void init() override;
    void draw() override;
    void logic() override;
    void cleaner() override;

    void resizeScreen() override;
};

#endif