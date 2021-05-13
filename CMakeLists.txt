cmake_minimum_required(VERSION 3.17)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

project(project_bomberman
        LANGUAGES CXX
        DESCRIPTION "Bomberman like game"
        )

set(MY_SRC
        #${PROJECT_SOURCE_DIR}/src/
        )

set(MY_INCLUDE
        ${PROJECT_SOURCE_DIR}/include
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