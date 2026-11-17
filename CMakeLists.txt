cmake_minimum_required(VERSION 3.16)

project(timetothink LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)

    include(FetchContent)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.2
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(raylib)

else()

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(RAYLIB REQUIRED IMPORTED_TARGET raylib)

endif()

add_executable(timetothink
    src/core/Main.cpp
    src/core/ScreenManager.cpp
    src/core/ScreenManager.hpp
    src/core/InputReader.hpp

    src/shared/ui/Ui.hpp
    src/shared/ui/Canvas.hpp
    src/shared/ui/utils/TextUtils.hpp
    src/shared/ui/utils/AnimationsUtils.hpp
    src/shared/ui/button/Button.hpp
    src/shared/ui/button/ButtonCustom.hpp
    src/shared/ui/text/Popup.hpp
    src/shared/ui/text/TextBox.hpp
    src/shared/ui/components/AnimatedMenu.hpp
    src/shared/ui/components/ButtonGroup.hpp

    src/screens/ScreenTemplate.hpp
    src/screens/lesson/Lesson.hpp
    src/screens/lesson/LessonElement.hpp
    src/screens/intro/IntroScreen.cpp
    src/screens/intro/IntroScreen.hpp
    src/screens/start/StartScreen.cpp
    src/screens/start/StartScreen.hpp
    src/screens/mainMenu/MainMenuScreen.cpp
    src/screens/mainMenu/MainMenuScreen.hpp
    src/screens/config/ConfigScreen.cpp
    src/screens/config/ConfigScreen.hpp
)

target_include_directories(timetothink PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

if(WIN32)
    target_link_libraries(timetothink PRIVATE raylib)
else()
    target_link_libraries(timetothink PRIVATE PkgConfig::RAYLIB)
endif()

install(TARGETS timetothink
    RUNTIME DESTINATION .
)

install(DIRECTORY assets/
    DESTINATION assets
)