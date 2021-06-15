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
    std::cout << "Player dctor\n";
}

//------------------

//EVENT

void Player::handleKeyEvent() noexcept
{
    gameEngine::encapsulation::Keyboard kb;

    for (const auto evt : _key_event) {
        try {
            if (kb.isKeyDown(evt.first)) {
                setState(ANIMWALK);
                std::cout << "key was pressed" << std::endl;
                std::cout << "Walking" << std::endl;
                playerKeyEvt my_action = _key_event.at(evt.first);
                CALL_MEMBER_FN((*this), my_action)(1);
            } else {
                std::cout << "Idling" << std::endl;
                setState(ANIMIDLE);
            }
        } catch (std::out_of_range &my_exception) {
        }
    }
}

void Player::update()
{
    handleKeyEvent();
    updateModelAnimation();
}
