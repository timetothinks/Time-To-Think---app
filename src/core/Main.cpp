#include <iostream>
#include "raylib.h"

#include "ScreenManager.hpp"
#include "InputReader.hpp"

#include "screens/intro/IntroScreen.hpp"
#include "screens/mainMenu/MainMenuScreen.hpp"
#include "screens/config/ConfigScreen.hpp"
#include "screens/start/StartScreen.hpp"
#include "screens/ScreenTemplate.hpp"

const int widthScreen = 800;
const int heightScreen = 600;

void createScreens() {
    ScreenManager::Instance().registerScreen(
        "intro", []() 
            { return new IntroScreen(ScreenManager::Instance()); 
        });
    ScreenManager::Instance().registerScreen(
        "main_menu", []() 
            { return new MainMenuScreen(ScreenManager::Instance()); 
        });
    ScreenManager::Instance().registerScreen(
        "start", []() 
            { return new StartScreen(ScreenManager::Instance()); 
        });
    ScreenManager::Instance().registerScreen(
        "config",  []() 
            { return new ConfigScreen(ScreenManager::Instance()); 
        });
}

int main() {
    // inicializacion
    std::cout << "Raylib ver: " << RAYLIB_VERSION;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(widthScreen, heightScreen, "TIME TO THINK (beta)");
    SetTargetFPS(60);

    ScreenManager& SM = ScreenManager::Instance();

    SM.loadResources();

    createScreens();
    ToggleFullscreen();

    SM.changeScreen("intro");

    // Main loop
    while(!WindowShouldClose()) { 
        InputReader::ReadGlobalInputs();
        SM.update();

        SM.changeScreenPending();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        SM.draw();

        EndDrawing();
    }

    SM.unloadResources();

    CloseWindow();

    return 0;
}