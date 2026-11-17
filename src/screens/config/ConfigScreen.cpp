#include "raylib.h"
#include <iostream>

#include "ConfigScreen.hpp"

#include "core/ScreenManager.hpp"

#include "shared/ui/Ui.hpp"
#include "shared/ui/button/Button.hpp"
#include "shared/ui/button/ButtonCustom.hpp"
#include "shared/ui/text/Popup.hpp"

void ConfigScreen::init() {
    tipSlider = new Popup("");

    float backButtonWidth = 350.0f;
    float backButtonHeight = 50.0f;

    backButton = new Button(
        0, 0, backButtonWidth, backButtonHeight, 
        "regresar", Fade(Color{150, 150, 170, 255}, 0.5f),
    [this]() {
         SM.changeScreen("main_menu");       
    });

    float sliderWidth = 400.0f;
    float sliderHeight = 25.0f;

    pseudoSlider = new ButtonCustom(0, 0, sliderWidth, sliderHeight, BLACK, 
    [this]() { // on mouse pass
        this->tipSlider->setText("podria ser un Slider si se me usa bien.");
        this->tipSlider->send(1.0f);
    },
    [this]() {

    },
    [this]() { // on click CustomButton
        SetWindowTitle("Easteregg???, ok... no");
    });

    uiElements.push_back(backButton);
    uiElements.push_back(pseudoSlider);
    uiElements.push_back(tipSlider);

    this->resizeScreen();
}

void ConfigScreen::resizeScreen() {
    backButton->setPosition(
        SM.getWidth(50.0f),
        SM.getHeight(20.0f)
    );

    pseudoSlider->setPosition(
        SM.getWidth(50.0f),
        SM.getHeight(50.0f)
    );

    tipSlider->setPosition(
        SM.getWidth(50.0f),
        SM.getHeight(90.0f)
    );
}

void ConfigScreen::draw() {
	DrawText("VENTANA CONFIG MENU", 0, 0, 10, BLACK);
	DrawText("aqui puedes implementar interfaz para editar las configuraciones del programa (sonido, color, ect)", 0, 10, 10, BLACK);

   for(auto element : uiElements) {
        element->draw();
   }
}

void ConfigScreen::logic() {
    for(auto element : uiElements) {
        element->logic();
    }
    
    if(IsWindowResized()) {
        this->resizeScreen();
    }
}

void ConfigScreen::cleaner() {  
    for(auto element : uiElements) {
        delete element;
    }
}