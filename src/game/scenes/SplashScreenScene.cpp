/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SplashScreenScene
*/

#include "SplashScreenScene.hpp"

using namespace game::scenes;

#define ATTACK_PATH "./assets/spriteSheets/SpriteSheet_Splash.png"
#define JUMP_PATH "./assets/spriteSheets/jump_in_Splash.png"
#define IDLE_PATH "./assets/spriteSheets/idle_splash.png"
#define LOGO "./assets/Logo/studio_logo.png"
#define ATTACK_FRAMES 11
#define JUMP_FRAMES 10
#define IDLE_FRAMES 9
#define JUMP_X 95
#define IDLE_X 93
#define ATTACK_X 140
#define NB_JUMPS 5

static size_t FRAME_SPEED = 8;

SplashScreenScene::SplashScreenScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info),
_attackRect(Vector<float>(140, 130)), _jumpRect(Vector<float>(95, 147)), _idleRect(Vector<float>(93, 115)),
_state(SplashScreenScene::JUMP), _attackFrame(0), _jumpFrame(0), _idleFrame(0), _currentFrame(0), _nbReset(0)
{
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadSoundFromFile("./assets/All/Sound/Hadoken.mp3", "hadoken");
    _audio->loadSoundFromFile("./assets/All/Sound/redcodeGames.wav", "redCode");
    _audio->loadSoundFromFile("./assets/All/Sound/Jump.wav", "jump");
    _audio->setSoundVolume(0.1f);
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::start()
{
    _attackText.loadFromFile(ATTACK_PATH);
    _jumpText.loadFromFile(JUMP_PATH);
    _idleText.loadFromFile(IDLE_PATH);
    _logo.loadFromFile(LOGO);
    _jumpText.setPos(Vector<int>(_windowManager->getWindowSize()._x, _windowManager->getWindowSize()._y / 2));
    _attackText.setPos(Vector<int>(_windowManager->getWindowSize()._x - 700, _windowManager->getWindowSize()._y / 2));
    _idleText.setPos(Vector<int>(_windowManager->getWindowSize()._x - 700, _windowManager->getWindowSize()._y / 2));
    _attackText.setEnabled(false);
    _logo.setEnabled(false);
    _jumpText.setEnabled(true);
    _idleText.setEnabled(false);
}

void SplashScreenScene::updateAnim(size_t &frame, size_t max, int multipler, gameEngine::encapsulation::BRectangle &rect)
{
    if (frame >= 60/FRAME_SPEED) {
        frame = 0;
        _currentFrame++;
        if (_currentFrame >= max) {
            _currentFrame = 0;
            _nbReset++;
        }
        rect.setX((float)_currentFrame * multipler);
    }
}

void SplashScreenScene::animJump()
{
    if (_currentFrame == 1)
        _audio->playSound("jump");
    _jumpFrame++;
    updateAnim(_jumpFrame, JUMP_FRAMES, JUMP_X, _jumpRect);
    if (_currentFrame < JUMP_FRAMES / 2) {
        _jumpText.setPos(Vector<int>(_jumpText.getPos()._x - 2, _jumpText.getPos()._y - 4));
    } else if (_currentFrame >= JUMP_FRAMES / 2) {
        _jumpText.setPos(Vector<int>(_jumpText.getPos()._x - 2, _jumpText.getPos()._y + 4));
    }
    if (_nbReset >= NB_JUMPS) {
        _jumpText.setEnabled(false);
        _idleText.setEnabled(true);
        _idleText.setPos(_jumpText.getPos());
        _state = IDLE;
        _nbReset = 0;
    }
}

void SplashScreenScene::animIdle()
{
    _idleFrame++;
    updateAnim(_idleFrame, IDLE_FRAMES, IDLE_X, _idleRect);
    if (_nbReset >= 3) {
        _idleText.setEnabled(false);
        _attackText.setEnabled(true);
        _attackText.setPos(_idleText.getPos());
        _state = ATTACK;
        _nbReset = 0;
    }
}

void SplashScreenScene::animAttack()
{
    if (_currentFrame == 0) {
        _audio->setSoundVolume(1);
        _audio->playSound("hadoken");
    }
    if (_currentFrame == 4) {
        _audio->playSound("redCode");
    }

    FRAME_SPEED = 4;
    _attackFrame++;
    updateAnim(_attackFrame, ATTACK_FRAMES, ATTACK_X, _attackRect);
    if (_currentFrame == 3) {
        Vector<int> playerPos = _attackText.getPos();
        _logo.setPos(Vector<int>(playerPos._x - _logo.getSize()._x, (playerPos._y + (_logo.getSize()._y / 2) - playerPos._y / 2) + 15));
        _logo.setEnabled(true);
    }
    if (_nbReset > 0) {
        _state = DONE;
        _attackText.setEnabled(false);
        _idleText.setEnabled(true);
        _clock.restart();
    }
}

std::string SplashScreenScene::done()
{
    if (_clock.getElapsedTime() > 3)
        return "menu";
    return "";
}

void SplashScreenScene::update()
{
    if (_info->_inputManager->getLastKeyPressedByAUser() == gameEngine::Key::KEY_SPACE)
        _state = SKIP;
    switch(_state) {
        case IDLE:
            animIdle();
            break;
        case JUMP:
            animJump();
            break;
        case ATTACK:
            animAttack();
            break;
        case DONE:
            animIdle();
            _info->setCurrentScene(done());
            break;
        case SKIP:
            _info->setCurrentScene("menu");
            break;
        default:
            break;
    }
}

void SplashScreenScene::draw()
{
    _windowManager->setBackgroundColor(BLACK);
    _attackText.drawRect(_attackRect, Vector<float>(_attackText.getPos()._x, _attackText.getPos()._y));
    _jumpText.drawRect(_jumpRect, Vector<float>(_jumpText.getPos()._x, _jumpText.getPos()._y));
    _idleText.drawRect(_idleRect, Vector<float>(_idleText.getPos()._x, _idleText.getPos()._y));
    _logo.draw();
    _skipText.draw();
}
