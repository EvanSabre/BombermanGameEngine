cmake_minimum_required(VERSION 3.17)

set(CMAKE_BUILD_TYPE Debug)

project(project_bomberman_lib
        LANGUAGES CXX
        DESCRIPTION "Bomberman library"
        )

set(MYLIB_SRC
        "${PROJECT_SOURCE_DIR}/scenes/MainMenuScene.cpp"
        )

set(MYLIB_INCLUDE
        "../../include"
        "../../include/game/"
        "../../include/game/scenes"
        "../../include/gameEngine"
        "../../include/gameEngine/encapsulation"
        "../../include/gameEngine/interfaces/"
        "../../include/gameEngine/managers"
        )

set(raylib_DIR ${PROJECT_SOURCE_DIR}/../../cmake)
find_package(raylib REQUIRED)

set(MY_DEPENDENCIES
        raylib
        )

add_library(gameLib SHARED ${MYLIB_SRC})

target_link_libraries(gameLib ${MY_DEPENDENCIES})
target_include_directories(gameLib BEFORE PUBLIC ${MYLIB_INCLUDE})
