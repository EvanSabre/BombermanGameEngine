/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#include "EmptyScene.hpp"

using namespace game::scenes;

EmptyScene::EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _text("HELLO BITE", 10), _parser("polo")
{
    _cam.setPosition({-20, 180, 70});
    _cam.setTarget({70, 0, 70});
    _cam.setUp({0, 1, 0});
    _cam.setFovy(55);
    _cam.setProjection(CAMERA_PERSPECTIVE);
}
EmptyScene::~EmptyScene()
{
}

void EmptyScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

    // for (auto &tile : tmp.getTiledMap()) {
    //     _tiles.push_back(std::make_shared<game::objects::Tile>(tile));
    // }
    // try {
    //     std::vector<game::systems::playerInfo_t> players = _parser.loadPlayers();
    //     for (auto it : players) {
    //         std::cout << "Name : " << it.name << std::endl;
    //         std::cout << it.tran << std::endl;
    //         std::cout << "Score : " << it.score << std::endl;
    //         std::cout << "Speed : " << it.speed << std::endl;
    //         std::cout << "Lives : " << it.lives << std::endl;
    //     }
    // } catch (SaveError &e) {
    //     std::cout << e.what() << std::endl;
    // }
}

void EmptyScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
}

void EmptyScene::draw()
{
    // this->_windowManager->set3DMode(_cam);
    // for (auto &tile : _tiles)
    //     tile->draw();
    // _cam.endMode();
}
