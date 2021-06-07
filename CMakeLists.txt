cmake_minimum_required(VERSION 3.17)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

project(project_bomberman
        LANGUAGES CXX
        DESCRIPTION "Bomberman like game"
        )

set(MY_SRC
       # ${PROJECT_SOURCE_DIR}/src/Vector.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/Animation.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BColor.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BText.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BRectangle.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BImage.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BCamera.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BCamera2D.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BModel.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BTexture2D.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BModelAnimation.cpp
        ${PROJECT_SOURCE_DIR}/src/game/managers/WindowManager.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/Keyboard.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/Button.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BFont.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BAudio.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BMusic.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BSound.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/BBoundingBox.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/systems/Move.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/systems/Collision.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/ADrawable.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/encapsulation/AAudioObject.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/objects/AGameObject.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/objects/Moveable.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/component/Transform.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/component/collider/Collider.cpp
        ${PROJECT_SOURCE_DIR}/src/gameEngine/component/collider/BoxCollider.cpp

        )

set(MY_INCLUDE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/gameEngine
        ${PROJECT_SOURCE_DIR}/include/gameEngine/objects
        ${PROJECT_SOURCE_DIR}/include/gameEngine/encapsulation
        ${PROJECT_SOURCE_DIR}/include/gameEngine/systems
        ${PROJECT_SOURCE_DIR}/include/gameEngine/component
        ${PROJECT_SOURCE_DIR}/include/gameEngine/component/collider
        ${PROJECT_SOURCE_DIR}/include/gameEngine/interfaces
        ${PROJECT_SOURCE_DIR}/include/game/managers
        )

set(raylib_DIR ${PROJECT_SOURCE_DIR}/cmake)
find_package(raylib REQUIRED)

set(MY_DEPENDENCIES
        raylib
        )

add_executable(bomberman
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${MY_SRC}
        )

set_target_properties(bomberman
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )

target_compile_features(bomberman PRIVATE cxx_std_17)

target_link_libraries(bomberman ${MY_DEPENDENCIES})

target_include_directories(bomberman BEFORE PUBLIC ${MY_INCLUDE})

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(bomberman PRIVATE -Wall -Wextra)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Window")
    target_compile_options(bomberman PRIVATE -Wall -Wextra)
endif ()
