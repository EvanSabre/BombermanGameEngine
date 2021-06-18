/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Player
*/

#include "Player.hpp"

using namespace game::objects;

Player::Player(const std::string &id, const std::string &name, const std::string &text,
                const std::string &model, const std::string &animWalk, const std::string &animIdle)
                : Character(id, name, text, model, animWalk, animIdle)
{
}

Player::~Player()
{
}

//------------------

//EVENT

void Player::handleKeyEvent() noexcept
{
    gameEngine::encapsulation::Keyboard kb;
    bool flag = false;

    for (const auto evt : _key_event) {
        try {
            if (kb.isKeyDown(evt.first)) {
                playerKeyEvt my_action = _key_event.at(evt.first);
                CALL_MEMBER_FN((*this), my_action)(1);
                flag = true;
                // std::cout << "Player\n" << this->getTransform() << std::endl;
            }
        } catch (std::out_of_range &my_exception) {
        }
    }
    setState(!flag ? ANIMIDLE : ANIMWALK);
}

void Player::update()
{
    handleKeyEvent();
    updateModelAnimation();
}
