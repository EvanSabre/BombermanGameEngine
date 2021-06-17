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
    std::cout << "Player dctor\n";
}

//------------------

//EVENT

void Player::handleKeyEvent() noexcept
{
    bool flag = false;

    for (const auto &[evt, action] : _key_event) {

        try {
            if (_currentEvent == evt) {
                std::cout << "key was pressed" << std::endl;
                playerKeyEvt my_action = action;
                CALL_MEMBER_FN((*this), my_action)(1);
                _currentEvent = NULL_EVENT;
                flag = true;
                std::cout << "Player\n" << this->getTransform() << std::endl;
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