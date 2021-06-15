/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Character
*/

#include "Character.hpp"

using namespace game::objects;

Character::Character(
                    const std::string &id,
                    const std::string &name,
                    const std::string &texturePath,
                    const std::string &model,
                    const std::string &animWalk,
                    const std::string &animIdle,
                    const Vector3T<float> &pos
                    ) : gameEngine::objects::Moveable(id), _frameCounter(0)
{
    _texture = std::make_shared<gameEngine::encapsulation::BTexture2D>(texturePath);
    _model = std::make_shared<gameEngine::encapsulation::BModel>(model);
    _animWalk = std::make_shared<gameEngine::encapsulation::BModelAnimation>(animWalk);
    _animIdle = std::make_shared<gameEngine::encapsulation::BModelAnimation>(animIdle);
    _anim = std::make_shared<gameEngine::encapsulation::BModelAnimation>(animIdle);
    // _animation = std::make_shared<gameEngine::Animation>(model, animWalk, animIdle, texturePath);
    _model->setTexture(0, MATERIAL_MAP_DIFFUSE, *_texture);
    _model->setTransform().setScale({0.01, 0.01, 0.01});
    this->_name = name;
    this->setTransform().setPosition(pos);
    _state = ANIMIDLE;
}

Character::~Character()
{
}

//getter

std::string Character::getName() const noexcept
{
    return this->_name;
}

size_t Character::getScore() const noexcept
{
    return this->_score;
}

int Character::getState() const noexcept
{
    return _state;
}


//setter

void Character::setState(const int &state) noexcept
{
    _state = state;
}

void Character::addScore(const size_t value) noexcept
{
    this->_score += value;
}

void Character::subScore(const size_t value) noexcept
{
    this->_score -= value;
}

void Character::setModel(std::shared_ptr<gameEngine::encapsulation::BModel> model) noexcept
{
    this->_model = model;
}

void Character::draw() const noexcept
{
    if (!this->_model)
        return;
    _model->setTransform().setPosition(this->_transform.getPosition());
    _model->setTransform().setRotation(this->_transform.getRotation());
    _model->setTransform().setScale(this->_transform.getScale());
    _model->rotate();
    _model->draw();
}

void Character::onCollisionEnter(const AGameObject &collision)
{
    try
    {
        std::unique_ptr<game::interfaces::IEffect> efx = game::objects::EffectFactory::makeEffect(collision.getTag());
        addPowerUpEffec(efx.get());
        return;
    }
    catch(const std::exception& e)
    {
    }

}

void Character::onCollisionExit(const AGameObject &collision) {}
void Character::update()
{
    updateModelAnimation();
}

void Character::updateModelAnimation()
{
    _anim = _state ? _animWalk : _animIdle;
    if (_model->isLoad() && _anim->isLoad()) {
        _frameCounter++;
        UpdateModelAnimation(_model->getObj(), _anim->getModelAnimation()[0], _frameCounter);
    }
    if (_frameCounter >= _anim->getAnimFrameCount()) {
        _frameCounter = 0;
    }
}

void Character::addPowerUpEffec(const game::interfaces::IEffect *efx) noexcept
{
    _lives += efx->getLife();
    _health += efx->getHealth();
    _nbBomb += efx->getNbBomb();
    _bombRange += efx->getBlastPower();
    _speed = _speed + efx->getSpeed();
}

game::Tag_e Character::getTag() const noexcept
{
    return  game::Tag::CHARACTER;
}
