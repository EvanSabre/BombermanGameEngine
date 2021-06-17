/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#include "PlayGameScene.hpp"

using namespace game::scenes;

PlayGameScene::PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _universe(UNIVERSE.at(std::rand() % UNIVERSE.size())), _map(_universe, 15)
{
    _map.dump();
    std::srand(_map.getSeed());
    std::shared_ptr<game::objects::Player> player = std::make_shared<game::objects::Player>("991", "Josh", "assets/" + _universe + "/Textures/Character.png", "assets/" + _universe + "/Models/Character.iqm", "assets/All/Animations/CharacterWalk.iqm", "assets/All/Animations/CharacterIdle.iqm");

    player->setTransform().setScale({0.1, 0.1, 0.1});
    player->setTransform().setPosition({10, 10, 10});
    player->setTransform().setRotation({90, 90, 0});
    player->setCollider();
    _players.push_back(player);
    this->setupCamera();
    _audio.loadMusicStreamFromFile("./assets/All/Music/Game.wav");
    _audio.loadSoundFromFile("./assets/All/Sound/Button.wav");
    for (auto &tile : _map.getTiledMap()) {
        _tiles.push_back(tile);
    }

    std::shared_ptr<gameEngine::encapsulation::BModel> healthModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/HealthUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> healthTex = std::make_shared<gameEngine::encapsulation::BTexture2D>("assets/All/Textures/Tile.png");
    _healtTile = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::HEALTHUP, Vector3T<float>{2, 0, 2},
        Vector3T<float>{0, 0, 0}, Vector3T<float>{5, 5, 5});
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    _timer.getCurrentTime().setTextPosition(Vector<float>(_windowManager->getWindowSize()._x /2, 30));
    _timer.startThread();
    _timer.getCurrentTime().setColor(RED);
    _timer.getCurrentTime().setTextSize(100);

    gameEngine::encapsulation::BText pauseText("PAUSE", Vector<float>(10, 10), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(50, 50), Vector<float>(10, 10), pauseText, BLUE);

    _audio.setSoundVolume(15.0);
    _audio.playSound();
    _buttonManager.pushButton(button);
    _windowManager->setBackgroundColor({0, 170, 170, 255});

    _audio.setMusicVolume(1.0); //1.0 is max level
    _audio.playMusic();
}

void PlayGameScene::setupCamera() noexcept
{
    _cam.setPosition({-20, 180, 70});
    _cam.setTarget({70, 0, 70});
    _cam.setUp({0, 1, 0});
    _cam.setFovy(55);
    _cam.setProjection(CAMERA_PERSPECTIVE);
}

void PlayGameScene::collisionChecker(std::shared_ptr<game::objects::Character> &player, const Vector3T<float> &prev)
{
    for (auto &tile : _tiles) {
        if (player->getCollider().isColliding(tile.getCollider().getBoundingBox())) {
            player->onCollisionEnter(tile);
            player->setTransform().setPosition(prev);
        }
    }
}

void PlayGameScene::update()
{
    _healtTile.get()->update();
    _buttonManager.updateButtons();
    _audio.updateMusicStream();
    if (!_windowManager->isRunning()) {
        _timer.setIsDone(true);
        _timer.wait();
        _info->setQuit(true);
    }
    if (_buttonManager.isButtonClicked("PAUSE")) {
        _timer.addToDuration(10);
        std::cout << "Clicked pause button" << std::endl;
        // _audio.pauseMusic();
        //return "play";
    }
    for (auto &it : _players) {
        Vector3T<float> prev(it->getTransform().getPosition());
        it->update();
        collisionChecker(it, prev);
    }
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();
    this->_windowManager->set3DMode(_cam);
    (*_healtTile).draw();
   // _map.draw();
    // for (auto it : _players) {
    //     it->draw();
    // }
    _cam.endMode();
    _timer.getCurrentTime().draw();
}
