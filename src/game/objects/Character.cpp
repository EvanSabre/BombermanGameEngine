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
    this->setPostion(pos);
    _tag = game::Tag::CHARACTER;
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
    _model->setPosition(this->getPosition());
    _model->draw();
}

void objects::Character::OnCollisionEnter(const AGameObject &collision) {}
void objects::Character::OnCollisionExit(const AGameObject &collision) {}
void objects::Character::Update() {}
game::Tag_e objects::Character::getTag() const noexcept
{
    return  _tag;
}
