/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Player
*/

#include "Player.hpp"

using namespace game::objects;

Player::Player(const std::string &id, const std::string &name, const std::string &text,
                const std::string &model, const std::string &animWalk, const std::string &animIdle, std::shared_ptr<game::User> &userLinked)
                : Character(id, name, text, model, animWalk, animIdle), _profil(userLinked)
{
}

Player::~Player()
{
}

//------------------

//EVENT

void Player::update()
{
    handleEvent();
    this->Character::update();
}
