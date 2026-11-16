#include "raylib.h"

#include "ScreenManager.hpp"
#include "screens/ScreenTemplate.hpp"
#include "screens/mainMenu/MainMenuScreen.hpp"

ScreenManager::ScreenManager() : currentScreen(nullptr) {}

ScreenManager::~ScreenManager() {
    if (currentScreen != nullptr) {
        currentScreen->cleaner();
        delete currentScreen;
    }
}

ScreenManager& ScreenManager::Instance() {
    static ScreenManager instance;
    return instance;
}

Texture2D ScreenManager::getTexture(const std::string& key) {
    auto txt = textures.find(key);
    if(txt != textures.end()) {
        return txt->second; 
    }
    TraceLog(LOG_WARNING, "TEXTURA NO ENCONTRADA EN EL MAPA: %s", key.c_str());
    return Texture2D{ 0 }; 
    
}

void ScreenManager::loadResources() {
    titleFont = LoadFontEx("assets/fonts/ArchivoBlack-Regular.ttf", 96, NULL, 0);
    titleTwoFont = LoadFontEx("assets/fonts/Anton-regular.ttf", 96, NULL, 0);
    casualFont = LoadFontEx("assets/fonts/JetBrainsMono-Italic-VariableFont_wght.ttf", 64, NULL, 0);
    buttonFont = LoadFontEx("assets/fonts/PressStart2P-Regular.ttf", 48, NULL, 0);

    static const int iconPacket[] = {
        0xEF3E,
        0xF0EB,
        0xEDC6,
        0xF525,
        0xEECB,
        0xEED2,
        0xEAD8,
        0xED3E,
        0xF5FC
    };
    int iconToLoad = sizeof(iconPacket) / sizeof(iconPacket[0]);
    iconsFont = LoadFontEx("assets/fonts/remixicon.ttf", 96, iconPacket, iconToLoad);

    SetTextureFilter(titleFont.texture, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(casualFont.texture, TEXTURE_FILTER_BILINEAR);  
    SetTextureFilter(titleTwoFont.texture, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(buttonFont.texture, TEXTURE_FILTER_POINT);
    SetTextureFilter(iconsFont.texture, TEXTURE_FILTER_BILINEAR);

    const std::string dir = "assets/images/main_background/white/";
    textures["bg_molecular"] = LoadTexture((dir + "molecular-sciences-svgrepo-com.png").c_str());
    textures["cube"] = LoadTexture((dir + "3d-cube-svgrepo-com.png").c_str());
    textures["chemical_form"] = LoadTexture((dir + "chemical-formula-svgrepo-com.png").c_str());
    textures["chemical_bottle"] = LoadTexture((dir + "flask-3-svgrepo-com.png").c_str());
    textures["idea"] = LoadTexture((dir + "idea-bulb-solution-business-svgrepo-com.png").c_str());
    textures["sigma_maths"] = LoadTexture((dir + "sigma-maths-svgrepo-com.png").c_str());
    textures["think_men"] = LoadTexture((dir + "thinking-svgrepo-com.png").c_str());
    textures["adn"] = LoadTexture((dir + "dna-svgrepo-com.png").c_str());
    textures["brain"] = LoadTexture((dir + "brain-illustration-1-svgrepo-com.png").c_str());
    textures["compass"] = LoadTexture((dir + "compass-maths-drawing-tool-svgrepo-com.png").c_str());
    textures["math_circle"] = LoadTexture((dir + "circles-graphic-design-svgrepo-com.png").c_str());
    textures["ball_graphic"] = LoadTexture((dir + "balls-and-lines-black-shape-svgrepo-com.png").c_str());
    textures["math_graphic"] = LoadTexture((dir + "data-svgrepo-com.png").c_str());

    textures["udg_logo"] = LoadTexture("assets/images/udg-red.png");

    textures["formula_1"] = LoadTexture("assets/images/lesson_formgeneral/formula1.png");
    textures["formula_2"] = LoadTexture("assets/images/lesson_formgeneral/formula2.png");
    textures["ecuacion"] = LoadTexture("assets/images/lesson_formgeneral/equation.png");
    textures["ecuacion_1"] = LoadTexture("assets/images/lesson_formgeneral/equation(1).png");
    textures["ecuacion_2"] = LoadTexture("assets/images/lesson_formgeneral/equation(2).png");
    textures["ecuacion_3"] = LoadTexture("assets/images/lesson_formgeneral/equation(3).png");
    textures["ecuacion_4"] = LoadTexture("assets/images/lesson_formgeneral/equation(4).png");
    textures["ecuacion_5"] = LoadTexture("assets/images/lesson_formgeneral/equation(5).png");
    textures["ecuacion_6"] = LoadTexture("assets/images/lesson_formgeneral/equation(6).png");
    textures["ecuacion_7"] = LoadTexture("assets/images/lesson_formgeneral/equation(7).png");
    textures["ecuacion_8"] = LoadTexture("assets/images/lesson_formgeneral/equation(8).png");
    textures["ecuacion_9"] = LoadTexture("assets/images/lesson_formgeneral/equation(9).png");
    textures["ecuacion_10"] = LoadTexture("assets/images/lesson_formgeneral/equation(10).png");

    textures["arrow"] = LoadTexture("assets/images/maths/arrow-right.png");
    textures["x"] = LoadTexture("assets/images/maths/x.png");
    textures["x_squared"] = LoadTexture("assets/images/maths/x_squared.png");
    textures["b_div_a"] = LoadTexture("assets/images/maths/b_div_a.png");
    textures["b_div_twoa"] = LoadTexture("assets/images/maths/b_div_twoa.png");
    textures["b_div_twoa_x"] = LoadTexture("assets/images/maths/b_div_twoa_x.png");
    textures["b_div_twoa_squared"] = LoadTexture("assets/images/maths/b_div_twoa_squared.png");
    textures["square_binomial"] = LoadTexture("assets/images/maths/square_binomial.png");

    for(auto& txt : textures) {
        SetTextureFilter(txt.second, TEXTURE_FILTER_BILINEAR);
    }

    for (auto& txt : textures) {
    TraceLog(
        LOG_INFO,
        "Texture: %s | ID: %u | Width: %i | Height: %i",
        txt.first.c_str(),
        txt.second.id,
        txt.second.width,
        txt.second.height
    );
}

}

void ScreenManager::unloadResources() {
    UnloadFont(titleFont);
    UnloadFont(casualFont);
    UnloadFont(buttonFont);
    UnloadFont(iconsFont);

    for(auto& txt : textures) {
        UnloadTexture(txt.second);
    }

    textures.clear();
}

Font ScreenManager::getFontRegular() { return titleFont; }
Font ScreenManager::getFontPressStar() { return buttonFont; }
Font ScreenManager::getFontIcons() { return iconsFont; }
Font ScreenManager::getFontJetbrains() { return casualFont; }
Font ScreenManager::getFontAnton() { return titleTwoFont; }

void ScreenManager::registerScreen(const std::string& name, std::function<ScreenTemplate*()> creator) {
    screenFactory[name] = creator;
}

void ScreenManager::changeScreen(const std::string& name) {
    if (screenFactory.find(name) != screenFactory.end()) {
        nextScreenName = name;
    } else {
        TraceLog(LOG_ERROR, "La pantalla '%s' no está registrada.", name.c_str());
    }
}

void ScreenManager::changeScreenPending() {
    if(nextScreenName.empty()) return;

    if (currentScreen != nullptr) {
        currentScreen->cleaner();
        delete currentScreen;
        currentScreen = nullptr;
    }

    currentScreen = screenFactory[nextScreenName]();
    currentScreen->init();
    
    nextScreenName.clear();
}

void ScreenManager::update() { if (currentScreen) currentScreen->logic(); }
void ScreenManager::draw() { if (currentScreen) currentScreen->draw(); }

float ScreenManager::getWidth(float percentage) {
    float currentWidth = IsWindowFullscreen() ? static_cast<float>(GetMonitorWidth(GetCurrentMonitor())) : static_cast<float>(GetScreenWidth());
    return currentWidth * (percentage / 100.0f);
}

float ScreenManager::getHeight(float percentage) {
    float currentHeight = IsWindowFullscreen() ? static_cast<float>(GetMonitorHeight(GetCurrentMonitor())) : static_cast<float>(GetScreenHeight());
    return currentHeight * (percentage / 100.0f);
}


