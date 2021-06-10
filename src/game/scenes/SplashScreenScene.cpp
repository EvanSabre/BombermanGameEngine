/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SplashScreenScene
*/

#include "SplashScreenScene.hpp"

using namespace game::scenes;

#define ATTACK_PATH "./resources/spriteSheets/SpriteSheet_Splash.png"
#define JUMP_PATH "./resources/spriteSheets/jump_in_Splash.png"
#define IDLE_PATH "./resources/spriteSheets/idle_splash.png"
#define ATTACK_FRAMES 11
#define JUMP_FRAMES 10
#define IDLE_FRAMES 9
#define JUMP_X 95
#define IDLE_X 93
#define ATTACK_X 140

static size_t FRAME_SPEED = 8;

SplashScreenScene::SplashScreenScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info)
: AScene(windowManager, info),
_attackRect(Vector<float>(140, 130)), _jumpRect(Vector<float>(95, 147)), _idleRect(Vector<float>(93, 115)),
_state(SplashScreenScene::JUMP), _attackFrame(0), _jumpFrame(0), _idleFrame(0), _currentFrame(0), _nbReset(0), _reset(false)
{
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::start()
{
    _attackText.loadFromFile(ATTACK_PATH);
    _jumpText.loadFromFile(JUMP_PATH);
    _idleText.loadFromFile(IDLE_PATH);
    _jumpText.setPos(Vector<int>(_windowManager->getWindowSize()._x, _windowManager->getWindowSize()._y / 2));
    _attackText.setPos(Vector<int>(_windowManager->getWindowSize()._x - 700, _windowManager->getWindowSize()._y / 2));
    _idleText.setPos(Vector<int>(_windowManager->getWindowSize()._x - 700, _windowManager->getWindowSize()._y / 2));
    _attackText.setEnabled(false);
    _jumpText.setEnabled(true);
    _idleText.setEnabled(false);
}

void SplashScreenScene::updateAnim(size_t &frame, size_t max, int multipler, gameEngine::encapsulation::BRectangle &rect)
{
    _reset = false;
    if (frame >= 60/FRAME_SPEED) {
        frame = 0;
        _currentFrame++;
        if (_currentFrame >= max) {
            _currentFrame = 0;
            _nbReset++;
            _reset = true;
        }
        rect.setX((float)_currentFrame * multipler);
    }
    _reset = false;
}

void SplashScreenScene::animJump()
{
    _jumpFrame++;
    updateAnim(_jumpFrame, JUMP_FRAMES, JUMP_X, _jumpRect);
    if (_currentFrame < JUMP_FRAMES / 2) {
        _jumpText.setPos(Vector<int>(_jumpText.getPos()._x - 2, _jumpText.getPos()._y - 4));
    } else if (_currentFrame >= JUMP_FRAMES / 2) {
        _jumpText.setPos(Vector<int>(_jumpText.getPos()._x - 2, _jumpText.getPos()._y + 4));
    }
    if (_nbReset >= 7) {
        _jumpText.setEnabled(false);
        _idleText.setEnabled(true);
        _idleText.setPos(_jumpText.getPos());
        _state = IDLE;
        _nbReset = 0;
    }
}

void SplashScreenScene::animAttack()
{
    _attackFrame++;
    FRAME_SPEED = 6;
    updateAnim(_attackFrame, ATTACK_FRAMES, ATTACK_X, _attackRect);
}

void SplashScreenScene::animIdle()
{
    _idleFrame++;
    updateAnim(_idleFrame, IDLE_FRAMES, IDLE_X, _idleRect);
    if (_nbReset >= 7) {
        _idleText.setEnabled(false);
        _attackText.setEnabled(true);
        _attackText.setPos(_idleText.getPos());
        _state = ATTACK;
        _nbReset = 0;
    }

}

std::string SplashScreenScene::update()
{
    switch(_state) {
        case IDLE:
            animIdle();
            break;
        case JUMP:
            animJump();
            break;
        case ATTACK:
            animAttack();
        default:
            break;
    }
    if (_reset)
        _nbReset++;
    return "";
}

void SplashScreenScene::draw()
{
    _windowManager->setBackgroundColor(BLACK);
    _attackText.drawRect(_attackRect, Vector<float>(_attackText.getPos()._x, _attackText.getPos()._y));
    _jumpText.drawRect(_jumpRect, Vector<float>(_jumpText.getPos()._x, _jumpText.getPos()._y));
    _idleText.drawRect(_idleRect, Vector<float>(_idleText.getPos()._x, _idleText.getPos()._y));
}
