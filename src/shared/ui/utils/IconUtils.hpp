#ifndef ICON_UTILS
#define ICON_UTILS

/**
 * @namespace Icons
 * @brief almacena todos los iconos utilizados de assets/fonts/JetBrainsMono-Italic-VariableFont_wght.ttf
 */

namespace Icons {
    const char* MENU_SIDEBAR   = "\xee\xbc\xbe"; 
    const char* LIGHTBULB      = "\xef\x83\xab"; 
    const char* COMPASS        = "\xee\xb7\x86"; 
    const char* BRAIN          = "\xef\x94\xa5"; 
    const char* ATOM           = "\xef\x97\xbc";    // Atom (U+F5FC)
    const char* POTION         = "\xee\xb4\xbe";  // Potion (U+ED3E)
    const char* BOOK           = "\xee\xab\x98";
    
    const char* LOCK           = "\xee\xbb\x8b"; 
    const char* UNLOCK         = "\xee\xbb\x92";

    void drawIcon(const char *iconByte, float x, float y, float size, Color color) {
        Font iconFont = ScreenManager::Instance().getFontIcons();
        
        Vector2 position = {x, y};
        DrawTextEx(iconFont, iconByte, position, size, 0.0f, color);
    }
};


#endif