/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#include "PlayGameScene.hpp"

using namespace game::scenes;
#define ANIMWALK_PATH "assets/All/Animations/CharacterWalk.iqm"
#define ANIMIDLE_PATH "assets/All/Animations/CharacterIdle.iqm"
#define SAVE_DIR "/Saves"
#define PLAYER_SAVE "/Players.save"
static const gameEngine::component::Transform BOT_LEFT_SPAWN(Vector3T<float>(10, 10, 10), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));
static const gameEngine::component::Transform TOP_LEFT_SPAWN(Vector3T<float>(130, 10, 10), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));
static const gameEngine::component::Transform BOT_RIGHT_SPAWN(Vector3T<float>(130, 10, 150), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));
static const gameEngine::component::Transform TOP_RIGHT_SPAWN(Vector3T<float>(10, 10, 150), Vector3T<float>(90, 90, 0), Vector3T<float>(0.1, 0.1, 0.1));

PlayGameScene::PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _map(_info->getUniverse(), _info->getSavedMap(), MAPSIZE), _pause(false)
{
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    std::string nb(std::to_string(std::rand() % 3));
    _audio->loadMusicStreamFromFile("./assets/All/Music/Game" + nb + ".wav");
    _audio->loadSoundFromFile("./assets/All/Sound/Bombdrop.wav", "drop");
    _audio->loadSoundFromFile("./assets/All/Sound/BombExplode.mp3", "boom");
    _audio->loadSoundFromFile("./assets/All/Sound/Button.wav", "button");
    _audio->loadSoundFromFile("./assets/All/Sound/CharacterDamage.wav", "damage");
    _audio->loadSoundFromFile("./assets/All/Sound/CharacterDeath.wav", "death");
    _audio->loadSoundFromFile("./assets/All/Sound/CollectibleDrop.wav", "itemDrop");
    _audio->loadSoundFromFile("./assets/All/Sound/CollectiblePick.wav", "itemPick");

    _audio->setMusicVolume((_info->getMusicVolume() - 20) / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
    _savePath = realpath("./", NULL);
    _savePath.append(SAVE_DIR);

    if (!std::filesystem::is_directory(_savePath)) {
        Directory _dir(std::string(_savePath), true);
    }
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    // std::string textStr = "assets/Vikings/Textures/Character.png";
    // std::string modelStr = "assets/Vikings/Models/Character.iqm";
    std::string textStr = "assets/" + _info->getUniverse() + "/Textures/Character.png";
    std::string modelStr = "assets/" + _info->getUniverse() + "/Models/Character.iqm";
    std::vector<gameEngine::component::Transform> SPAWNS = {
        BOT_LEFT_SPAWN,
        BOT_RIGHT_SPAWN,
        TOP_LEFT_SPAWN,
        TOP_RIGHT_SPAWN
    };
    std::array<std::string, 3> botNames = {"Bot_Bob", "Bot_Michel", "Bot_Jacquie"};
    std::vector<gameEngine::component::Transform>::iterator spawnIt = SPAWNS.begin();

    _map.dump();
    std::srand(_map.getSeed());
    for (auto &tile : _map.getTiledMap()) {
        _tiles.push_back(std::make_shared<game::objects::Tile>(tile));
    }

    if (!_info->getIsSave()) {
        for (auto it : _info->_players) {
            std::shared_ptr<game::objects::Player> player =
            std::make_shared<game::objects::Player>(std::to_string(it->Id), it->name, textStr, modelStr, ANIMWALK_PATH, ANIMIDLE_PATH, it);
            player->setTransform().setScale(spawnIt->getScale());
            player->setTransform().setPosition(spawnIt->getPosition());
            player->setTransform().setRotation(spawnIt->getRotation());
            player->setCollider();
            spawnIt++;
            _players.push_back(player);
        }
        for (size_t i = 0; i < (size_t)_info->nbBots; i++) {
            std::shared_ptr<game::objects::Bot> bot =
            std::make_shared<game::objects::Bot>(std::to_string(i + 1), botNames.at(i), textStr, modelStr, ANIMWALK_PATH, ANIMIDLE_PATH, _tiles, 0, Vector<int>(15, 17));
            bot->setTransform().setScale(spawnIt->getScale());
            bot->setTransform().setPosition(spawnIt->getPosition());
            bot->setTransform().setRotation(spawnIt->getRotation());
            bot->setCollider();
            spawnIt++;
            _players.push_back(bot);
        }
    } else {
        for (auto it : _info->getSavedPlayers()) {
            if (it.name.find("Bot") == it.name.npos) {
                std::shared_ptr<game::objects::Player> player =
                std::make_shared<game::objects::Player>("1", it.name, textStr, modelStr, ANIMWALK_PATH, ANIMIDLE_PATH, _info->_userManager->getUser(it.name));
                player->setTransform() = it.tran;
                player->addScore(it.score);
                player->setSpeed(it.speed);
                player->setLives(it.lives);
                player->setCollider();
                _players.push_back(player);
            } else {
                std::shared_ptr<game::objects::Bot> bot =
                std::make_shared<game::objects::Bot>("1", it.name, textStr, modelStr, ANIMWALK_PATH, ANIMIDLE_PATH, _tiles, 0, Vector<int>(15,17));
                bot->setTransform() = it.tran;
                bot->setCollider();
                _players.push_back(bot);
            }
        }
    }

    this->setupCamera();

    // std::shared_ptr<gameEngine::encapsulation::BModel> healthModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/HealthUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    // std::shared_ptr<gameEngine::encapsulation::BTexture2D> healthTex = std::make_shared<gameEngine::encapsulation::BTexture2D>("assets/All/Textures/Tile.png");
    //     Vector3T<float>{0, 0, 0}, Vector3T<float>{5, 5, 5});

    _timer.getCurrentTime().setTextPosition(Vector<float>(_windowManager->getWindowSize()._x /2, 30));
    _timer.startThread();
    _timer.getCurrentTime().setColor(RED);
    _timer.getCurrentTime().setTextSize(100);

    gameEngine::encapsulation::BText pauseText("PAUSE", Vector<float>(100, 30), WHITE, 20);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 40), Vector<float>(10, 10), pauseText, DARKGRAY, WHITE, PLAY_BUTTON);

    setupPause();
    _buttonManager.pushButton(button);
    _windowManager->setBackgroundColor({0, 170, 170, 255});
    _explosion = std::make_shared<game::managers::ExplosionManager>(_players, _tiles);
    // _audio->playMusic();
}

void PlayGameScene::setupPause()
{
    Vector<float> size(300, 200);
    Vector<float> middle2(_windowManager->getWindowSize()._x/3 - size._x / 2 + size._x, _windowManager->getWindowSize()._y/3 - size._y / 2);

    gameEngine::encapsulation::BText resumeText("RESUME", Vector<float>(middle2._x + 60, middle2._y + 15), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> resume =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y), resumeText, DARKGRAY, WHITE, PLAY_BUTTON);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText saveText("SAVE", Vector<float>(middle2._x + 80, middle2._y + 15), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSave =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y), saveText, DARKGRAY, WHITE, PLAY_BUTTON);

    gameEngine::encapsulation::BText inputText("Enter a Save name", Vector<float>(middle2._x, middle2._y), WHITE, 20);
    _saveInput =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(300, 50), middle2, 10, inputText, RED, false, BLACK);
    _saveInput->setEnabled(false);
    _savePopUp = std::make_unique<gameEngine::component::PopUp>("Successfully saved game", Vector<float>(middle2._x + 80, middle2._y - 10), Vector<float>(270, 150));
    _savePopUp->setEnabled(false);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText settingsText("SETTINGS", Vector<float>(middle2._x + 40, middle2._y + 15), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSettings =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y), settingsText, DARKGRAY, WHITE, PLAY_BUTTON);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText quitText("QUIT", Vector<float>(middle2._x + 80, middle2._y + 15), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y), quitText, DARKGRAY, WHITE, PLAY_BUTTON);


    _pauseManager.pushButton(resume);
    _pauseManager.pushButton(buttonSave);
    _pauseManager.pushButton(buttonQuit);
    _pauseManager.pushButton(buttonSettings);
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
    game::objects::Character p(*player);
    p.setTransform().setPosition(prev);
    p.setCollider();

    for (auto tile = _tiles.begin(); tile != _tiles.end();) {
        if (player->getCollider().isColliding((*tile)->getCollider().getBoundingBox()) &&
            !p.getCollider().isColliding((*tile)->getCollider().getBoundingBox())) {
            player->setTransform().setPosition(prev);
            player->setIsMoving(false);
            player->onCollisionEnter(*(*tile));
            if ((*tile)->getTag() == BOMB)
                (*tile)->done();
            if ((*tile)->getTag() == ONEUP || (*tile)->getTag() == BOMBUP ||
                (*tile)->getTag() == HEALTHUP || (*tile)->getTag() == FIREUP ||
                (*tile)->getTag() == BOMBPASS || (*tile)->getTag() == SPEEDUP) {
                _audio->playSound("itemPick");
                _tiles.erase(tile);
                continue;
            }
        }
        tile++;
    }
}

void PlayGameScene::updateExplosionManager()
{
    _explosion->setObjects(_players, _tiles);
    _explosion->update();
    _tiles = _explosion->getTiles();
    _players = _explosion->getPlayers();

    auto array = _explosion->getBombs();
    for (auto &bomb : array) {
        // std::cout << bomb->getTransform() << std::endl;
        _tiles.push_back(bomb);
    }
}

void PlayGameScene::savePlayers()
{
    File file = _fileManager.loadFile(_savePath + "/" + _saveInput->getContent() + PLAYER_SAVE, true);
    std::string text;
    std::stringstream ss;

    for (auto it : _players) {
        ss << "Player : " << it->getName() << std::endl;
        ss << "Transform :" << it->getTransform();
        ss << "Lives : " << it->getLives() << std::endl;
        ss << "Speed : " << it->getSpeed() << std::endl;
        ss << "Score : " << it->getScore() << std::endl;
        ss << "####" << std::endl;
        text = ss.str();
        ss.clear();
    }
    _fileManager.writeFile(file, text, true);
}

void PlayGameScene::updatePause()
{
    _pauseManager.updateButtons();
    _saveInput->update();
    _savePopUp->update();
    if (_pauseManager.isButtonClicked("RESUME")) {
        _pause = false;
        _timer.setPause(false);
        _audio->playSound("button");
    }
    if (_pauseManager.isButtonClicked("SAVE")) {
        _saveInput->setEnabled(true);
        _pauseManager.setEnabledButton("SAVE", false);
    }
    if (_pauseManager.isButtonClicked("QUIT")) {
        _timer.setPause(false);
        _audio->playSound("button");
        quit();
    }
    if (_saveInput->getEnabled() && _saveInput->checkValidate()) {
        _map.saveMap(_tiles, _savePath + "/" + _saveInput->getContent());
        savePlayers();
        _savePopUp->setEnabled(true);
        _saveInput->setEnabled(false);
        _pauseManager.setEnabledButton("SAVE", true);
    }
}

void PlayGameScene::drawPause()
{
    _saveInput->draw();
    _pauseManager.drawButtons();
    _savePopUp->draw();
}

void PlayGameScene::quit()
{
    _timer.setIsDone(true);
    _timer.wait();
    _info->setQuit(true);
}

void PlayGameScene::update()
{
    //updateExplosionManager();
    _buttonManager.updateButtons();
    if (!_windowManager->isRunning())
        quit();
    if (_buttonManager.isButtonClicked("PAUSE")) {
        _pause = true;
        _timer.setPause(true);
    }
    if (_pause) {
        updatePause();
        return;
    }
    std::vector<std::pair<int, game::Event>> events = _info->_inputManager->pollEvents();
    for (auto &[id, evt]: events)
    {
        if ((std::size_t)id <= _players.size()) {
            _players[id - 1]->setCurrentEvent(evt);
        }
    }
    for (auto &tile : _tiles) {
        tile->update();
    }
    for (auto &player : _players) {
        Vector3T<float> prev(player->getTransform().getPosition());
        auto list = player->getBombQueue();
        player->update();
        collisionChecker(player, prev);
        if (player->hasDropped()) {
            _audio->playSound("drop");
            for (auto &bomb : list) {
                if (bomb->getSwitch()) {
                    _explosion->pushBomb(bomb);
                }
                bomb->setSwitch(false);
            }
        }
        player->setDropped(false);
    }
    updateExplosionManager();
    _audio->updateMusicStream();
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();

    this->_windowManager->set3DMode(_cam);
    for (auto &it : _players) {
        it->draw();
    }
    for (auto &tile : _tiles)
        tile->draw();
    _explosion->draw();
    _cam.endMode();
    _timer.getCurrentTime().draw();
    if (_pause) {
        drawPause();
    } else {
        _buttonManager.drawButtons();
    }
    int idx_player = 0;
    for (auto &it : _players) {
        _gui.draw((*it), (game::Gui::corner_e)idx_player);
        idx_player++;
    }
}
