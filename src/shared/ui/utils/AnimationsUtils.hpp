#ifndef ANIMATIONS_UTILS
#define ANIMATIONS_UTILS    

#include "raylib.h"
#include <string>

/**
 * @namespace AnimationsUtils
 * 
 * @brief Utils para crear animaciones sin repetir codigo
 */
namespace AnimationsUtils {

      /** 
       * @brief crea una animacion para rectangulos de cierre y apertura con desplazamiento desde su ancho
       * como la utilizada para @ref AnimatedMenu
       * @param bounds Rectangle al que se le quiere animar
       * @param targetWidth ancho del Rectangle
       * @param animationSpeed velocidad de la animacion
       * @param isOpen ve si el rectangulo esta "cerrado" o "abierto" para definir la animacion
       */
      inline void SlideWidth(Rectangle& bounds, float targetWidth, float animationSpeed, bool isOpen) {
        float time = GetFrameTime();
        
        if(isOpen) {
            if (bounds.width < targetWidth) {
                bounds.width += animationSpeed * time;
                if (bounds.width > targetWidth) bounds.width = targetWidth;
            }
        } else {
            if (bounds.width > 0.0f) {
                bounds.width -= animationSpeed * time;
                if (bounds.width < 0.0f) bounds.width = 0.0f;
            }
        }
    }

    /// @brief Anima el desplazamiento de un rectangulo en su eje x 
    /// @param bounds rectangulo que se quiere animar
    /// @param targetX 
    /// @param closeX 
    /// @param speed velocidad de animacion
    /// @param shouldOpen ve si esta "abierto" o "cerrado" para definir la animacion
    inline void SlidePositionX(Rectangle& bounds, float targetX, float closeX, float speed, bool shouldOpen) {
        float deltaTime = GetFrameTime();
        
        if (shouldOpen) {
            if (bounds.x < targetX) { // Suponiendo que entra de izquierda a derecha
                bounds.x += speed * deltaTime;
                if (bounds.x > targetX) bounds.x = targetX;
            }
        } else {
            if (bounds.x > closeX) {
                bounds.x -= speed * deltaTime;
                if (bounds.x < closeX) bounds.x = closeX;
            }
        }
    }

}

#endif