/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#ifndef EMPTYSCENE_HPP_
#define EMPTYSCENE_HPP_

#include "AScene.hpp"
#include "Timer.hpp"
#include "BSdf.hpp"
#include "BModel.hpp"
#include "Selector.hpp"
#include "TSelector.hpp"
#include "Map.hpp"
#include "LoadParser.hpp"

#define WINDOW_X _windowManager->getWindowSize()._x
#define WINDOW_Y _windowManager->getWindowSize()._y

namespace game {
    namespace scenes {
        class EmptyScene : public gameEngine::AScene {
            public:
                EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info);
                ~EmptyScene();

                void start() override;
                void update() override;
                void draw() override;
            protected:
                gameEngine::encapsulation::BSdf _text;
                game::systems::LoadParser _parser;
                gameEngine::component::Timer _timer;
                std::unique_ptr<gameEngine::component::TSelector<gameEngine::encapsulation::BModel>> _universeSelector = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BTexture2D> _tmp;
                gameEngine::encapsulation::BCamera _cam;
                std::vector<std::shared_ptr<game::objects::Tile>> _tiles;
            private:
        };
    }
}

#endif /* !EMPTYSCENE_HPP_ */
