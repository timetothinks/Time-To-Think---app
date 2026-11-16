#ifndef INPUT_READER
#define INPUT_READER

#include "raylib.h"

/**
 * @namespace InputReader
 * 
 * @brief tiene funciones para manejar los inputs generales 
 */
namespace InputReader {
    /**
     * 
     * @brief Lee y procesa todos los atajos de teclado con ctrl+(tecla)
     * 
     * @details Los atajos de teclado generalmente deben de ser independientes a 
     * otras pantallas, pues para un atajo de teclado de una pantalla se deberia
     * definir dentro de su logica en @ref ScreenTemplate::logic()
     */
    inline void ReadGlobalInputs() {
        if(IsKeyDown(KEY_LEFT_CONTROL)) {
            //window control
            if(IsKeyPressed(KEY_F)) { 
                ToggleFullscreen();
            }
        }

    }
}

#endif