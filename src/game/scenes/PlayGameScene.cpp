/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#include "PlayGameScene.hpp"

using namespace game::scenes;

PlayGameScene::PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info)
: AScene(windowManager, info), _map(15)
{
    std::shared_ptr<game::objects::Player> player = std::make_shared<game::objects::Player>("991", "Josh", "assets/Vikings/Textures/Character.png", "assets/Vikings/Model/Character.iqm", "assets/Vikings/Animation/CharacterWalk.iqm", "assets/Vikings/Animation/CharacterIdle.iqm");
    player->setTransform().setScale({0.1, 0.1, 0.1});
    player->setTransform().setPosition({10, 10, 10});
    player->setTransform().setRotation({90, 90, 0});
    player->setCollider();
    // std::cout << "player :" << std::endl;
    // std::cout <<
    //     "\tbox_min = {" << player->getCollider().getBoundingBox().getMin()._x << ", "
    //                   << player->getCollider().getBoundingBox().getMin()._y << ", "
    //                   << player->getCollider().getBoundingBox().getMin()._z << "}" << std::endl;
    // std::cout <<
    //     "\tbox_max = {" << player->getCollider().getBoundingBox().getMax()._x << ", "
    //                   << player->getCollider().getBoundingBox().getMax()._y << ", "
    //                   << player->getCollider().getBoundingBox().getMax()._z << "}" << std::endl;
    _players.push_back(player);
    this->setupCamera();
    for (auto &tile : _map.getTiledMap()) {
        _tiles.push_back(tile);
        // std::cout << "tile :" << std::endl;
        // std::cout <<
        //     "\tbox_min = {" << tile.getCollider().getBoundingBox().getMin()._x << ", "
        //                 << tile.getCollider().getBoundingBox().getMin()._y << ", "
        //                 << tile.getCollider().getBoundingBox().getMin()._z << "}" << std::endl;
        // std::cout <<
        //     "\tbox_max = {" << tile.getCollider().getBoundingBox().getMax()._x << ", "
        //                 << tile.getCollider().getBoundingBox().getMax()._y << ", "
        //                 << tile.getCollider().getBoundingBox().getMax()._z << "}" << std::endl;
    }
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(50, 50), Vector<float>(10, 10), gameEngine::encapsulation::BText("PAUSE"), BLUE);

    _buttonManager.pushButton(button);
    _windowManager->setBackgroundColor({0, 170, 170, 255});
}

void PlayGameScene::setupCamera() noexcept
{
    _cam.setPosition({-70, 200, 70});
    _cam.setTarget({70, 0, 70});
    _cam.setUp({0, 1, 0});
    _cam.setFovy(55);
    _cam.setProjection(CAMERA_PERSPECTIVE);
}

void PlayGameScene::collisionChecker(std::shared_ptr<game::objects::Character> &player, const Vector3T<float> &prev)
{
    DrawBoundingBox(player->getCollider().getBoundingBox()._box, RED);
    for (auto &tile : _tiles) {
        if (player->getCollider().isColliding(tile.getCollider().getBoundingBox())) {
            player->onCollisionEnter(tile);
            player->setTransform().setPosition(prev);
        }
    }
}

std::string PlayGameScene::update()
{
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PAUSE")) {
        std::cout << "Clicked pause button" << std::endl;
        //return "play";
    }
    for (auto &it : _players) {
        Vector3T<float> prev(it->getTransform().getPosition());
        it->update();
        collisionChecker(it, prev);
    }
    return "";
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();
    this->_windowManager->set3DMode(_cam);
    _map.draw();
    for (auto it : _players) {
        it->draw();
    }
    _cam.endMode();
}
