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
                    const Vector3T<float> &pos
                    ) : gameEngine::objects::Moveable(id)
{
    this->_name = name;
    this->setTransform().setPosition(pos);
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

//setter
void Character::addScore(const size_t value) noexcept
{
    this->_score += value;
}

void Character::subScore(const size_t value) noexcept
{
    this->_score -= value;
}

void Character::setModel(gameEngine::encapsulation::BModel *model) noexcept
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
void Character::update() {}

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
