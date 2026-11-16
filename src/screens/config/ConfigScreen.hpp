#ifndef CONFIG_SCREEN
#define CONFIG_SCREEN

#include <vector>

#include "screens/ScreenTemplate.hpp"
#include "shared/ui/Ui.hpp"

class Button;
class ButtonCustom;
class Popup;

class ConfigScreen : public ScreenTemplate {

private:
std::vector<Ui*> uiElements;

Button* backButton;
ButtonCustom* pseudoSlider;
Popup* tipSlider;

public:
    ConfigScreen(ScreenManager& sm) : ScreenTemplate(sm) {}

    void init() override;
    void draw() override;
    void logic() override;
    void cleaner() override;

    void resizeScreen() override;
};

#endif