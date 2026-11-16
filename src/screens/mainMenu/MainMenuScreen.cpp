#include "raylib.h"
#include <iostream>
#include "algorithm"
#include "MainMenuScreen.hpp"

#include "shared/ui/button/Button.hpp"
#include "shared/ui/components/AnimatedMenu.hpp"
#include "shared/ui/components/ButtonGroup.hpp"
#include "shared/ui/Canvas.hpp"
#include "shared/ui/utils/IconUtils.hpp"
#include "core/ScreenManager.hpp"

void MainMenuScreen::init() {
    demoTest = new Button(
        0, 0, 400, 70, 
        "Prueba la DEMO!!", (Color){56, 189, 248, 255}, 
    [this]() {
        SM.changeScreen("start");
    }, 24.0f, SM.getFontJetbrains());

    auto sendRGB = [](int val) -> unsigned char {
        return static_cast<unsigned char>(std::max(0, std::min(255, val)));
    };

    auto colorGradient = [sendRGB](Color color, int degradation) -> Color {
        return (Color){
            sendRGB(color.r-degradation), 
            sendRGB(color.g-degradation),
            sendRGB(color.b-degradation),
        255};
    };

    // MAIN MENU BUTTONS

    Color menuColor = (Color){200, 230, 230, 255};
    Color menuColorRigth = colorGradient((menuColor), 20);

    sciencesMenu = new AnimatedMenu(
        330, 60, catalogMenuWidth, catalogMenuHeight, 
        menuColorRigth, 
        menuColor,
        ColorLerp(menuColor, menuColorRigth, 0.5f),
        "  Catalogo de \n"
        "    ciencias ", 
    [] (const Rectangle& content) {
        
    },
    [this]() {
        for(auto menu : menus) {
            if(menu == sciencesMenu) continue;
            if(menu->isMenuLocked()) menu->toggleMenuLocked();
        }
    }, 
    [this] (){
        for(auto menu : menus) {
            if(menu == sciencesMenu) continue;
            menu->setVisible(false);
        }
    },
    [this] (){
        if(this->sciencesMenu->isMenuLocked()) {
            for(auto menu : menus) {
                if(menu == sciencesMenu) continue;
                menu->setVisible(false);
            }
        } else {
            for(auto menu : menus) {
                if(menu == sciencesMenu) continue;
                menu->setVisible(true);
            }
        }
    });

    CLMenu = new AnimatedMenu(
        330, 60, catalogMenuWidth, catalogMenuHeight, 
        menuColorRigth, 
        menuColor,
        ColorLerp(menuColor, menuColorRigth, 0.5f),
        "  Catalogo de \n"
        "    ciencias ", 
    [] (const Rectangle& content) {
        
    },
    [this]() {
        for(auto menu : menus) {
            if(menu == CLMenu) continue;
            if(menu->isMenuLocked()) menu->toggleMenuLocked();
        }
    }, 
    [this] (){
        for(auto menu : menus) {
            if(menu == CLMenu) continue;
            menu->setVisible(false);
        }
    },
    [this] (){
        if(this->CLMenu->isMenuLocked()) {
            for(auto menu : menus) {
                if(menu == CLMenu) continue;
                menu->setVisible(false);
            }
        } else {
            for(auto menu : menus) {
                if(menu == CLMenu) continue;
                menu->setVisible(true);
            }
        }
    });

    chemicalMenu = new AnimatedMenu(
        330, 60, catalogMenuWidth, catalogMenuHeight, 
        menuColorRigth, 
        menuColor,
        ColorLerp(menuColor, menuColorRigth, 0.5f),
        "  Catalogo de \n"
        "    ciencias ", 
    [] (const Rectangle& content) {
        
    },
    [this]() {
        for(auto menu : menus) {
            if(menu == chemicalMenu) continue;
            if(menu->isMenuLocked()) menu->toggleMenuLocked();
        }
    }, 
    [this] (){
        for(auto menu : menus) {
            if(menu == chemicalMenu) continue;
            menu->setVisible(false);
        }
    },
    [this] (){
        if(this->chemicalMenu->isMenuLocked()) {
            for(auto menu : menus) {
                if(menu == chemicalMenu) continue;
                menu->setVisible(false);
            }
        } else {
            for(auto menu : menus) {
                if(menu == chemicalMenu) continue;
                menu->setVisible(true);
            }
        }
    });

    phisycMenu = new AnimatedMenu(
        330, 60, catalogMenuWidth, catalogMenuHeight, 
        menuColorRigth, 
        menuColor,
        ColorLerp(menuColor, menuColorRigth, 0.5f),
        "  Catalogo de \n"
        "    ciencias ", 
    [] (const Rectangle& content) {
        
    },
    [this]() {
        for(auto menu : menus) {
            if(menu == phisycMenu) continue;
            if(menu->isMenuLocked()) menu->toggleMenuLocked();
        }
    }, 
    [this] (){
        for(auto menu : menus) {
            if(menu == phisycMenu) continue;
            menu->setVisible(false);
        }
    },
    [this] (){
        if(this->phisycMenu->isMenuLocked()) {
            for(auto menu : menus) {
                if(menu == phisycMenu) continue;
                menu->setVisible(false);
            }
        } else {
            for(auto menu : menus) {
                if(menu == phisycMenu) continue;
                menu->setVisible(true);
            }
        }
    });

    mathsMenu = new AnimatedMenu(
        330, 60, catalogMenuWidth, catalogMenuHeight, 
        menuColor, 
        menuColorRigth,
        ColorLerp(menuColor, menuColorRigth, 0.5f),
        "  Catalogo de \n"
        "  Matematicas", 
    [] (const Rectangle& content) {
        
    },
    [this]() {
        for(auto menu : menus) {
            if(menu == mathsMenu) continue;
            if(menu->isMenuLocked()) menu->toggleMenuLocked();
        }
    }, 
    [this] (){
        for(auto menu : menus) {
            if(menu == mathsMenu) continue;
            menu->setVisible(false);
        }
    },
    [this] (){
        if(this->mathsMenu->isMenuLocked()) {
            for(auto menu : menus) {
                if(menu == mathsMenu) continue;
                menu->setVisible(false);
            }
        } else {
            for(auto menu : menus) {
                if(menu == mathsMenu) continue;
                menu->setVisible(true);
            }
        }
    });

    logicMenu = new AnimatedMenu(
        330, 60, catalogMenuWidth, catalogMenuHeight, 
        menuColor, 
        menuColorRigth,
        ColorLerp(menuColor, menuColorRigth, 0.3f),
        "  Catalogo de \n"
        "    pensamiento LCC", 
    [] (const Rectangle& content) {
        
    },
    [this]() {
        for(auto menu : menus) {
            if(menu == logicMenu) continue;
            if(menu->isMenuLocked()) menu->toggleMenuLocked();
        }
    }, 
    [this] (){
        for(auto menu : menus) {
            if(menu == logicMenu) continue;
            menu->setVisible(false);
        }
    },
    [this] (){
        if(this->logicMenu->isMenuLocked()) {
            for(auto menu : menus) {
                if(menu == logicMenu) continue;
                menu->setVisible(false);
            }
        } else {
            for(auto menu : menus) {
                if(menu == logicMenu) continue;
                menu->setVisible(true);
            }
        }
    });

    catalogContent = new ButtonGroup(catalogButtonWidth, catalogButtonHeight, 10.0f, 10.0f, 8.0f);
    catalogContent->addButton("Introduccion al curso", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Nivel media 1", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Nivel media 2", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Nivel media 3", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Nivel media superior 1", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Nivel media superior 2", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Nivel media superior 3", catalogButtonColor, 
    []() {

    });
    catalogContent->addButton("Creditos y citas", catalogButtonColor, 
    []() {

    });

    menus.push_back(sciencesMenu);
    menus.push_back(mathsMenu);
    menus.push_back(logicMenu);
    menus.push_back(CLMenu);
    menus.push_back(chemicalMenu);
    menus.push_back(phisycMenu);

    uiElements.push_back(demoTest);
    for(auto menu : menus) {
        uiElements.push_back(menu);
    }
    uiElements.push_back(catalogContent);

    this->resizeScreen();
}

void MainMenuScreen::resizeScreen() {
    demoTest->setPosition(
        SM.getWidth(65.0f),
        SM.getHeight(15.0f)
    );
    sciencesMenu->setPosition(
        SM.getWidth(5.0f),
        SM.getHeight(20.0f)
    );
    mathsMenu->setPosition(
        SM.getWidth(5.0f),
        SM.getHeight(40.0f)
    );
    logicMenu->setPosition(
        SM.getWidth(35.0f),
        SM.getHeight(20.0f)
    );
    CLMenu->setPosition(
        SM.getWidth(35.0f),
        SM.getHeight(40.0f)
    );
    chemicalMenu->setPosition(
        SM.getWidth(5.0f),
        SM.getHeight(60.0f)
    );
    phisycMenu->setPosition(
        SM.getWidth(35.0f),
        SM.getHeight(60.0f)
    );
    
    Rectangle targetBox = {0, 0, 0, 0};

    if(sciencesMenu->isMenuShow()) {
        targetBox = sciencesMenu->getCanvasBounds(); 
    } else if(mathsMenu->isMenuShow()) {
        targetBox = mathsMenu->getCanvasBounds();
    } else if(logicMenu->isMenuShow()) {
        targetBox = logicMenu->getCanvasBounds();
    } else if(CLMenu->isMenuShow()) {
        targetBox = CLMenu->getCanvasBounds();
    }  else if(chemicalMenu->isMenuShow()) {
        targetBox = chemicalMenu->getCanvasBounds();
    } else if(phisycMenu->isMenuShow()) {
        targetBox = phisycMenu->getCanvasBounds();
    }

    if (targetBox.width > 10.0f) {
        targetBox.x += 20.0f;       // Margen izquierdo interior
        targetBox.y += 50.0f;       // Bajamos 80px para no encimarnos sobre el título del menú
        targetBox.width -= 40.0f;   // Restamos el padding a los lados
        targetBox.height -= 50.0f; // Restamos el espacio superior e inferior

        catalogContent->setPositionInBounds(targetBox);
    }
}


void MainMenuScreen::DrawBackgroundTexture(
    const std::string& textureName,
    float x, float y, float width, float height,
    float rotation,
    Color color,
    float opacity) {
    Texture2D txt = SM.getTexture(textureName);
    if(txt.id > 0) {
        DrawTexturePro(
            txt,
            Rectangle{0.0f, 0.0f, (float)txt.width, (float)txt.height},
            Rectangle{SM.getWidth(x), SM.getHeight(y), SM.getWidth(width), SM.getHeight(height)},
            Vector2{0.0f, 0.0f}, 
            rotation, 
            Fade(color, opacity)
        );
    }
}

void MainMenuScreen::draw() {
    ClearBackground((Color){11, 20, 36, 255});

    DrawRectangleGradientV(
        static_cast<int>(SM.getWidth(0.0f)),
        static_cast<int>(SM.getHeight(100.0f) - 100.0f),
        static_cast<int>(SM.getWidth(100.0f)),
        100,
        (Color){11, 20, 36, 255},
        BLACK
    );
    DrawRectangleGradientV(
        0, 0,
        static_cast<int>(SM.getWidth(100.0f)),
        200,
        BLACK,
        (Color){11, 20, 36, 255}
        ); 
	DrawTextEx(
        SM.getFontRegular(), "Time To Think",
        (Vector2){50.0f, 25.0f}, 96.0f, 4.0f, RAYWHITE
    );
    DrawBackgroundTexture("sigma_maths", 80.0f, 30.0f, 14.0f, 20.0f, 0.0f, GOLD);
    DrawBackgroundTexture("math_circle", 74.1f, 40.4f, 12.0f, 12.0f, 25.0f, DARKBLUE);
    DrawBackgroundTexture("ball_graphic", 80.0f, 60.4f, 15.0f, 12.0f, 0.0f, LIME);
    DrawBackgroundTexture("math_graphic", 70.0f, 30.0f, 14.0f, 14.0f, 0.0f, SKYBLUE);

    DrawBackgroundTexture("cube", 42.0f, 25.0f, 24.0f, 24.0f, 0.0f,(Color){0, 160, 45, 255}, 0.12f);
    DrawBackgroundTexture("compass", 34.0f, 35.0f, 12.0f, 12.0f, 0.0f, MAGENTA, 0.07);

    DrawBackgroundTexture("brain", 51.0f, 60.0f, 24.0f, 24.0f, 0.0f, RED, 0.12f);
    DrawBackgroundTexture("idea", 55.4f, 47.0f, 15.0f, 15.0f, 0.0f, (Color){173, 183, 0, 255});
    DrawBackgroundTexture("adn", 44.0f, 56.0f, 12.0f, 16.0f, 30.0f, PURPLE);
    DrawBackgroundTexture("think_men", 75.0f, 73.0f, 12.0f, 12.0f, 25.0f, BEIGE);

    DrawBackgroundTexture("bg_molecular", 5.0f, 45.0f, 30.0f, 30.0f, 0.0f, (Color){0, 117, 240, 255}, 0.12f);
    DrawBackgroundTexture("chemical_bottle", 8.0f, 35.0f, 12.0f, 12.0f, -10.0f, (Color){170, 16, 192, 255});
    DrawBackgroundTexture("chemical_form", 33.0f, 40.0f, 12.0f, 12.0f, 40.0f, MAROON);

    DrawTextEx(SM.getFontJetbrains(), 
    "Creado por\n- Gomez Parra Salvador Rafael \n- Sepulveda Naranjo Roberto Josue",
    (Vector2){370.0f, (SM.getHeight(85.0f))}, 
    16.0f, 2.0f, Fade(GRAY, 0.5f)
    );

    for(auto element : uiElements) {
        if(element->isVisible()) {
            element->draw();
        }
    }

    std::vector<MenuIcon> menuIcons = {
        {mathsMenu, Icons::COMPASS, 35.0f, 20.0f },
        {sciencesMenu, Icons::BRAIN, (5.0f), (20.0f) },
        {logicMenu, Icons::LIGHTBULB, (5.0f), (40.0f) },
        {CLMenu, Icons::BOOK, (35.0f), (40.0f) },
        {chemicalMenu, Icons::POTION, (5.0f), (60.0f) },
        {phisycMenu, Icons::ATOM, (35.0f), (60.0f) }
    };

    bool anyVisible = 
    sciencesMenu->isVisible() || mathsMenu->isVisible() ||
    logicMenu->isVisible() || CLMenu->isVisible() ||
    chemicalMenu->isVisible() || phisycMenu->isVisible();

    for(const auto& item : menuIcons) {
        if(!anyVisible || item.menu->isVisible()) {
            Icons::drawIcon(
            item.icon,
            SM.getWidth(item.x),
            SM.getHeight(item.y),
            32,
            BLACK
            );
        }
    }
}

void MainMenuScreen::logic() {
    for(auto element : uiElements) {
        if(element->isVisible()) {
            element->logic();
        }
    }    

    bool isMenuOpen = 
    (this->sciencesMenu->isMenuShow() || this->sciencesMenu->isMenuLocked()) ||
    (this->logicMenu->isMenuShow() || this->logicMenu->isMenuLocked()) ||
    (this->mathsMenu->isMenuShow() || this->mathsMenu->isMenuLocked()) ||
    (this->CLMenu->isMenuShow() || this->CLMenu->isMenuLocked()) ||
    (this->chemicalMenu->isMenuShow() || this->chemicalMenu->isMenuLocked()) ||
    (this->phisycMenu->isMenuShow() || this->phisycMenu->isMenuLocked());

    catalogContent->setVisible(isMenuOpen);

    if(isMenuOpen || IsWindowResized()) {
        this->resizeScreen();
    }
}

void MainMenuScreen::cleaner() {
    for(auto element : uiElements) {
        delete element;
    }
}