#include "raylib.h"
#include <vector>

#include "StartScreen.hpp"

#include "screens/lesson/Lesson.hpp"
#include "screens/lesson/LessonElement.hpp"

void StartScreen::init() {
    lesson = new Lesson();

    float titleSize = 25.0f;
    float textSize = 20.0f;

    float squareOneWidth = 10.0f;
    float squareOneHeight = 45.0f;
    float squareOneSize = 200.0f;
    float squareTwoWidth = 70.0f;

    Color lessonColor = Fade(Color{70, 136, 170, 255}, 0.5f); 

    addFrame = new Button(
        SM.getWidth(5.0f), SM.getHeight(95.0f), 150, 50,  
        "regresar", lessonColor,
    [this]() {
        lesson->nextFrame();
    });

    quitFrame = new Button(
        SM.getWidth(80.0f), SM.getHeight(95.0f), 150, 50, 
        "siguiente", lessonColor,
    [this]() {
        lesson->previousFrame();     
    });


    questionOne = new Button(
        SM.getWidth(20.0f), SM.getHeight(40.0f), 400, 150,  
        "Es el minimo exponente \n""en la incognita", lessonColor,
    [this]() {
        this->startColorTransition(RED);
        this->ansewerOne = "Respuesta incorrecta \n"
                           "lee con mas atencion";
    });
    questionTwo = new Button(
        SM.getWidth(20.0f), SM.getHeight(60.0f), 400, 150, 
        "Es la dificultad que \n""los matematicos atribuyen", lessonColor,
    [this]() {
        this->startColorTransition(RED);
        this->ansewerOne = "Respuesta incorrecta \n"
                           "lee con mas atencion";
    });
    questionThree = new Button(
        SM.getWidth(60.0f), SM.getHeight(60.0f), 400, 150,  
        "Es el maximo exponente\n""en la incognita", lessonColor,
    [this]() {
        this->startColorTransition(GREEN);
        this->ansewerOne = "Respuesta correcta \n"
                           "felicidades has aprendido bien los conceptos";
    });
    questionFour = new Button(
        SM.getWidth(60.0f), SM.getHeight(40.0f), 400, 150, 
        "Es la cantidad de incognitas", lessonColor,
    [this]() {
        this->startColorTransition(RED);
        this->ansewerOne = "Respuesta incorrecta \n"
                           "lee con mas atencion";  
    });

    questionFive = new Button(
        SM.getWidth(20.0f), SM.getHeight(40.0f), 400, 150,  
        "Ninguna de las anteriores", lessonColor,
    [this]() {
        this->startColorTransition(RED);
        this->ansewerOne = "Respuesta incorrecta \n"
                           "lee con mas atencion";
    });
    questionSix = new Button(
        SM.getWidth(20.0f), SM.getHeight(60.0f), 400, 150, 
        "x al cuadrado", lessonColor,
    [this]() {
        this->startColorTransition(RED);
        this->ansewerOne = "Respuesta incorrecta \n"
                           "lee con mas atencion";
    });
    questionSeven = new Button(
        SM.getWidth(60.0f), SM.getHeight(60.0f), 400, 150,  
        "b entre 2a al cuadrado", lessonColor,
    [this]() {
        this->startColorTransition(GREEN);
        this->ansewerOne = "Respuesta correcta \n"
                           "felicidades has aprendido bien los conceptos";
    });
    questionFinal = new Button(
        SM.getWidth(60.0f), SM.getHeight(40.0f), 400, 150, 
        "b al cuadrado", lessonColor,
    [this]() {
        this->startColorTransition(RED);
        this->ansewerOne = "Respuesta incorrecta \n"
                           "lee con mas atencion";  
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n tema: ecuaciones de segundo grado",
            Vector2{SM.getWidth(3.0f), SM.getHeight(3.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("formula_1"),
            (SM.getWidth(35.0f)), 
            (SM.getHeight(40.0f))
        },
        LessonElement::Text{
            "   Forma general de una ecuacion de segundo grado \n \n"
            "Recordemos que una ecuacion de segundo grado es aquella \n"
            " que su maximo exponente en su incognita esta elevado \n"
            "                   al cuadrado (2). \n"
            "El grado de una ecuacion se define por el maximo exponente \n"
            "             en la incognita de la ecuacion. \n \n"
            "Nuestro objetivo sera despejar x en esta forma general \n"
            "                    de la ecuacion",
            Vector2{SM.getWidth(29.0f), SM.getHeight(48.0f)},
            textSize, WHITE
        },

        this->addFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n tema: ecuaciones de segundo grado",
            Vector2{SM.getWidth(3.0f), SM.getHeight(3.0f)},
            titleSize, WHITE
        },
        LessonElement::Text{
            "       CUESTIONARIO \n"
            "como se define una ecuacion \n"
            "    de segundo grado?",
            Vector2{SM.getWidth(35.0f), SM.getHeight(20.0f)},
            30.0f, WHITE
        },
        LessonElement::Text{
            this->ansewerOne,
            Vector2{SM.getWidth(30.0f), SM.getHeight(90.0f)},
            titleSize, WHITE
        },

        this->questionOne,
        this->questionTwo,
        this->questionThree,
        this->questionFour,

        this->quitFrame,
        this->addFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n tema: ecuaciones de segundo grado",
            Vector2{SM.getWidth(3.0f), SM.getHeight(3.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("formula_2"),
            (SM.getWidth(34.0f)), 
            (SM.getHeight(20.0f))
        },
        LessonElement::Text{
            " Primero dividimos todos los monomios de la ecuacion \n"
            "entre el termino (a), por igualdad la ecuacion seguira \n"
            "           siendo igual a 0, por ejemplo: \n"
            "10 + 15 - 25 = 0 \n"
            "10/5 + 15/5 - 25/5 = 0 \n"
            "2  + 3 - 5 = 0 \n"
            "Usamos esta igualdad matematica por conveniencia para \n"
            "poder despejar x, lo que nos lleva al siguiente paso \n \n"
            "              simplificando nos queda:",
            Vector2{SM.getWidth(29.0f), SM.getHeight(40.0f)},
            textSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion"),
            (SM.getWidth(32.0f)), 
            (SM.getHeight(70.0f))
        },

        this->addFrame,
        this->quitFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n ecuaciones de segundo grado",
            Vector2{SM.getWidth(0.0f), SM.getHeight(0.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(10.0f))
        },
        LessonElement::SquareLines{
            SM.getWidth(9.0f), 
            SM.getHeight(9.0f),
            280.0f, 150.0f
        },
        LessonElement::Square{
            SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight), 
            squareOneSize, squareOneSize, Color{145, 0, 0, 255}
        },
        LessonElement::Square{
            SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight)+squareOneSize, 
            squareOneSize, 180.0f, Color{0, 41, 94, 255}
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight) + squareOneSize+180},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize, SM.getHeight(squareOneHeight)},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize, SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize, SM.getHeight(squareOneHeight) + squareOneSize+180},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight) + squareOneSize+180},
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize, SM.getHeight(squareOneHeight) + squareOneSize+180},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight) + squareOneSize},
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize, SM.getHeight(squareOneHeight) + squareOneSize},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareOneWidth), SM.getHeight(squareOneHeight) + squareOneSize+90},
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Image{
            SM.getTexture("x"),
            (SM.getWidth(squareOneWidth)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize/2  - 20.0f)
        },
        LessonElement::Image{
            SM.getTexture("x"),
            (SM.getWidth(squareOneWidth) + squareOneSize/2 - 20.0f), 
            (SM.getHeight(squareOneHeight) - 40.0f)
        },
        LessonElement::Image{
            SM.getTexture("x_squared"),
            (SM.getWidth(squareOneWidth)+(squareOneSize/2.0f) -26.0f), 
            (SM.getHeight(squareOneHeight)+ (squareOneSize/4.0f) +10.0f)
        },
        LessonElement::Image{
            SM.getTexture("b_div_a"),
            (SM.getWidth(squareOneWidth) - 45.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize + 45.0f), WHITE, 0.7f
        },

        LessonElement::Image{
            SM.getTexture("b_div_twoa_x"),
            (SM.getWidth(squareOneWidth) + (squareOneSize/2.0f)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize), WHITE, 0.6f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa_x"),
            (SM.getWidth(squareOneWidth) + (squareOneSize/2.0f)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize + 90.0f), WHITE, 0.6f
        },


        LessonElement::Square{
            SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight), 
            squareOneSize, squareOneSize, Color{145, 0, 0, 255}
        },
        LessonElement::Square{
            SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight)+squareOneSize, 
            squareOneSize, 90.0f, Color{0, 41, 94, 255}
        },
        LessonElement::Square{
            SM.getWidth(squareTwoWidth)+squareOneSize, SM.getHeight(squareOneHeight), 
            90.0f, squareOneSize, Color{0, 41, 94, 255}
        },


        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize, SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight)},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight) + squareOneSize},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight) + squareOneSize},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight) + squareOneSize+90},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },

        LessonElement::Image{
            SM.getTexture("x"),
            (SM.getWidth(squareTwoWidth)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize/2  - 20.0f)
        },
        LessonElement::Image{
            SM.getTexture("x"),
            (SM.getWidth(squareTwoWidth) + squareOneSize/2 - 20.0f), 
            (SM.getHeight(squareOneHeight) - 40.0f)
        },
        LessonElement::Image{
            SM.getTexture("x_squared"),
            (SM.getWidth(squareTwoWidth)+(squareOneSize/2.0f) -26.0f), 
            (SM.getHeight(squareOneHeight)+ (squareOneSize/4.0f) +10.0f)
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa"),
            (SM.getWidth(squareTwoWidth) - 50.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize), WHITE, 0.7f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa"),
            (SM.getWidth(squareTwoWidth) + squareOneSize + 15.0f), 
            (SM.getHeight(squareOneHeight)-87.0f), WHITE, 0.7f
        },

        LessonElement::Image{
            SM.getTexture("b_div_twoa_x"),
            (SM.getWidth(squareTwoWidth) + (squareOneSize/2.0f)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize), WHITE, 0.6f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa_x"),
            (SM.getWidth(squareTwoWidth) + (squareOneSize)+90.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize/2.0f)-40.0f, WHITE, 0.6f, 90.0f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa_squared"),
            (SM.getWidth(squareTwoWidth) + (squareOneSize)+90.0f/3.0f - 20.0f), 
            (SM.getHeight(squareOneHeight) + (squareOneSize)+90.0f/3.0f) - 20.0f, WHITE, 0.5f
        
        },

        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(squareOneWidth) + squareOneSize/2 - 20.0f), 
            (SM.getHeight(squareOneHeight) - 40.0f), WHITE, 1.0f, -90.0f,
        },
        LessonElement::Text{
            "   Como vemos podemos transformar\n"
            "    este polinomio en un -binomio \n"
            " al cudrado- donde solo nos queda un \n"
            "  termino para completarlo, el cual \n"
            " recordando que la forma de un binomio \n"
            "es a al cuadrado mas dos veces el primer \n"
            "   por el segundo termino al cuadrado, \n"
            "  podemos deducir que falta el segundo \n"
            "         termino al cuadrado. \n" 
            "por lo que podemos simplificar x cuadrada \n" 
            "      en todo un binomio al cuadrado. \n \n"
            "Nos queda la siguiente expresion geometrica.",
            Vector2{SM.getWidth(squareOneWidth) + squareOneSize + 30.0f, SM.getHeight(squareOneHeight)},
            textSize, WHITE
        },

        this->addFrame,
        this->quitFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n tema: ecuaciones de segundo grado",
            Vector2{SM.getWidth(3.0f), SM.getHeight(3.0f)},
            titleSize, WHITE
        },
        LessonElement::Text{
            "       CUESTIONARIO \n"
            "que falta para completar el \n"
            "    binomio al cuadrado?",
            Vector2{SM.getWidth(35.0f), SM.getHeight(20.0f)},
            30.0f, WHITE
        },
        LessonElement::Text{
            this->ansewerOne,
            Vector2{SM.getWidth(30.0f), SM.getHeight(90.0f)},
            titleSize, WHITE
        },

        this->questionFive,
        this->questionSix,
        this->questionSeven,
        this->questionFinal,

        this->quitFrame,
        this->addFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n ecuaciones de segundo grado",
            Vector2{SM.getWidth(0.0f), SM.getHeight(0.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("square_binomial"),
            (SM.getWidth(70.0f)), 
            (SM.getHeight(3.0f)), WHITE, 0.6f
        },
        LessonElement::Text{
            "Nota: recordemos la forma general del \n"
            "binomio al cuadrado.",
            Vector2{SM.getWidth(70.0f), SM.getHeight(10.0f)},
            textSize, WHITE
        },

        LessonElement::Square{
            SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight), 
            squareOneSize, squareOneSize, Color{145, 0, 0, 255}
        },
        LessonElement::Square{
            SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight)+squareOneSize, 
            squareOneSize, 90.0f, Color{0, 41, 94, 255}
        },
        LessonElement::Square{
            SM.getWidth(squareTwoWidth)+squareOneSize, SM.getHeight(squareOneHeight), 
            90.0f, squareOneSize, Color{0, 41, 94, 255}
        },


        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize, SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight)},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight)},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight) + squareOneSize},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight) + squareOneSize},
            WHITE, 2.0f
        },
        LessonElement::Line{
            Vector2{SM.getWidth(squareTwoWidth), SM.getHeight(squareOneHeight) + squareOneSize+90},
            Vector2{SM.getWidth(squareTwoWidth) + squareOneSize+90, SM.getHeight(squareOneHeight) + squareOneSize+90},
            WHITE, 2.0f
        },

        LessonElement::Image{
            SM.getTexture("x"),
            (SM.getWidth(squareTwoWidth)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize/2  - 20.0f)
        },
        LessonElement::Image{
            SM.getTexture("x"),
            (SM.getWidth(squareTwoWidth) + squareOneSize/2 - 20.0f), 
            (SM.getHeight(squareOneHeight) - 40.0f)
        },
        LessonElement::Image{
            SM.getTexture("x_squared"),
            (SM.getWidth(squareTwoWidth)+(squareOneSize/2.0f) -26.0f), 
            (SM.getHeight(squareOneHeight)+ (squareOneSize/4.0f) +10.0f)
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa"),
            (SM.getWidth(squareTwoWidth) - 50.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize), WHITE, 0.7f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa"),
            (SM.getWidth(squareTwoWidth) + squareOneSize + 15.0f), 
            (SM.getHeight(squareOneHeight)-87.0f), WHITE, 0.7f
        },

        LessonElement::Image{
            SM.getTexture("b_div_twoa_x"),
            (SM.getWidth(squareTwoWidth) + (squareOneSize/2.0f)-40.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize), WHITE, 0.6f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa_x"),
            (SM.getWidth(squareTwoWidth) + (squareOneSize)+90.0f), 
            (SM.getHeight(squareOneHeight) + squareOneSize/2.0f)-40.0f, WHITE, 0.6f, 90.0f
        },
        LessonElement::Image{
            SM.getTexture("b_div_twoa_squared"),
            (SM.getWidth(squareTwoWidth) + (squareOneSize)+90.0f/3.0f - 20.0f), 
            (SM.getHeight(squareOneHeight) + (squareOneSize)+90.0f/3.0f) - 20.0f, WHITE, 0.5f
        
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_1"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(10.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_2"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(40.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_3"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(70.0f)), WHITE, 0.8f
        },
        LessonElement::SquareLines{
            SM.getWidth(9.0f), 
            SM.getHeight(39.0f),
            220.0f, 150.0f
        },
        LessonElement::SquareLines{
            SM.getWidth(9.0f), 
            SM.getHeight(69.0f),
            220.0f, 150.0f
        },
        LessonElement::SquareLines{
            SM.getWidth(9.0f), 
            SM.getHeight(9.0f),
            390.0f, 150.0f
        },
        
        this->addFrame,
        this->quitFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n ecuaciones de segundo grado",
            Vector2{SM.getWidth(0.0f), SM.getHeight(0.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_4"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(10.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(50.0f)), 
            (SM.getHeight(10.0f)), WHITE, 0.8f
        },
        LessonElement::Text{
            "Desarrollamos la resta de las dos fracciones",
            Vector2{SM.getWidth(55.0f), SM.getHeight(10.0f)},
            textSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_5"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(40.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(50.0f)), 
            (SM.getHeight(40.0f)), WHITE, 0.8f
        },
        LessonElement::Text{
            "simplificamos el binomio al sacarle raiz cuadrada, \n"
            "por lo que nos queda un lado del binomio, \n"
            "o lo que es lo mismo, la raiz cuadrada",
            Vector2{SM.getWidth(55.0f), SM.getHeight(40.0f)},
            textSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_6"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(70.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(50.0f)), 
            (SM.getHeight(70.0f)), WHITE, 0.8f
        },
        LessonElement::Text{
            "desarrollamos el cuadrado \n"
            "de b entre 2a al cuadrado",
            Vector2{SM.getWidth(55.0f), SM.getHeight(70.0f)},
            textSize, WHITE
        },

        this->addFrame,
        this->quitFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n ecuaciones de segundo grado",
            Vector2{SM.getWidth(0.0f), SM.getHeight(0.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_7"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(10.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(50.0f)), 
            (SM.getHeight(10.0f)), WHITE, 0.8f
        },
        LessonElement::Text{
            "Desarrollamos la resta de las dos fracciones\n"
            "manteniendo la igualdad",
            Vector2{SM.getWidth(55.0f), SM.getHeight(10.0f)},
            textSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_8"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(40.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(50.0f)), 
            (SM.getHeight(40.0f)), WHITE, 0.8f
        },
        LessonElement::Text{
            "sacamos raiz cuadrada a 4a cuadrada, por lo que nos \n"
            "queda 2a y dejamos raiz cuadrada en el numerador",
            Vector2{SM.getWidth(55.0f), SM.getHeight(40.0f)},
            textSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_10"),
            (SM.getWidth(10.0f)), 
            (SM.getHeight(70.0f)), WHITE, 0.8f
        },
        LessonElement::Image{
            SM.getTexture("arrow"),
            (SM.getWidth(50.0f)), 
            (SM.getHeight(70.0f)), WHITE, 0.8f
        },
        LessonElement::Text{
            "Pasamos la expresion b entre 2a para el otro lado de la \n"
            "igualdad, por lo que dejamos totalmente despejada X!!",
            Vector2{SM.getWidth(55.0f), SM.getHeight(70.0f)},
            textSize, WHITE
        },

        this->addFrame,
        this->quitFrame
    });

    lesson->addFrame({
        LessonElement::Text{
            "Leccion: formula general \n ecuaciones de segundo grado",
            Vector2{SM.getWidth(0.0f), SM.getHeight(0.0f)},
            titleSize, WHITE
        },
        LessonElement::Image{
            SM.getTexture("ecuacion_10"),
            (SM.getWidth(30.0f)), 
            (SM.getHeight(20.0f))
        },
        LessonElement::Text{
            "   Finalmente despejamos X, por lo que hayamos \n"
            " lo que la famosa Fomula general!, asi que ahora \n"
            " entendemos porque al usar esta curiosa formula \n"
            "podemos sacar los dos valores de x automaticamente",
            Vector2{SM.getWidth(25.0f), SM.getHeight(40.0f)},
            titleSize, WHITE
        },

        this->quitFrame
    });

    this->resizeScreen();
}

void StartScreen::resizeScreen() {
    
}

void StartScreen::draw() {
    ClearBackground(backgroundColor);
    lesson->draw();
}

void StartScreen::logic() {
    if(IsKeyPressed(KEY_RIGHT)) lesson->nextFrame();
    if(IsKeyPressed(KEY_LEFT)) lesson->previousFrame();

    lesson->logic();

    if(startTransition && transition < 1.0f) {
        transition += 2.0f * GetFrameTime();

        if (transition > 1.0f) { 
            this->startTransition = false;
            transition = 1.0f;
        }

        backgroundColor = ColorLerp(transitionColor, BLACK, transition);
    }
    
    if(IsWindowResized()) {
        this->resizeScreen();
    }
}   

void StartScreen::cleaner() {  
    delete lesson;
    delete quitFrame;
    delete addFrame;
}