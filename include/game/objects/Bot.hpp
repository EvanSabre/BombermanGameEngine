/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Bot
*/

#ifndef BOT_HPP_
#define BOT_HPP_

#include "Character.hpp"
#include "Brain.hpp"
namespace game
{
    namespace objects
    {
        class Bot : public Character, public systems::Brain
        {
            public:
                Bot(const std::string &id, const std::string &name, const std::string &text,
                    const std::string &model, const std::string &animWalk, const std::string &animIdl,
                    std::vector<std::shared_ptr<game::objects::Tile>> &map, int level, Vector<int> sizeMap);
                ~Bot();
                void update() override;

                Vector3T<float> getMiddlePos(const Vector3T<float> &pos);
                gameEngine::component::Clock _clock;
            protected:
            private:
        };
    }
}

#endif /* !BOT_HPP_ */
