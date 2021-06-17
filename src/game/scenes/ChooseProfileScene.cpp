/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ChooseProfileScene
*/

#include "ChooseProfileScene.hpp"

using namespace game::scenes;
#define BACKGROUND_BUTTON "./assets/Backgrounds/SupernovaBG.png"

ChooseProfileScene::ChooseProfileScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info) :
AScene(windowManager, info)
{
}

ChooseProfileScene::~ChooseProfileScene()
{
}
