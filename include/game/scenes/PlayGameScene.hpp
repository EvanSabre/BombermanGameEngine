/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#ifndef PLAYGAMESCENE_HPP_
#define PLAYGAMESCENE_HPP_

#include "AScene.hpp"
#include "ButtonManager.hpp"
#include "AudioManager.hpp"
#include "Map.hpp"
#include "BCamera.hpp"
#include "Player.hpp"
#include "BModel.hpp"
#include "BTexture2D.hpp"
#include "CheckBox.hpp"
#include "Timer.hpp"
#include "ExplosionManager.hpp"
#include "Bot.hpp"
#include "PowerUpTile.hpp"
#include "Gui.hpp"
#include "InputButton.hpp"
#include "PopUp.hpp"

namespace game {
    namespace scenes {
        class PlayGameScene : public gameEngine::AScene {
            public:
                PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~PlayGameScene();

                void setupPause();
                void collisionChecker(std::shared_ptr<game::objects::Character> &, const Vector3T<float> &);
                void drawPause();
                void updatePause();
                void start() override;
                void update() override;
                void draw() override;
                void updateExplosionManager();
                void quit();
                void savePlayers();
            protected:
            private:
                game::Gui _gui;
                Map _map;
                bool _pause;
                gameEngine::encapsulation::BCamera _cam;
                std::shared_ptr<gameEngine::managers::AudioManager> _audio = nullptr;
                std::vector<std::shared_ptr<game::objects::Character>> _players;
                std::vector<std::shared_ptr<game::objects::Tile>> _tiles;
                gameEngine::component::Timer _timer;
                std::shared_ptr<game::managers::ExplosionManager> _explosion;
                gameEngine::managers::ButtonManager _pauseManager;
                std::vector<std::shared_ptr<game::objects::Character>> _tab{0};
                gameEngine::managers::AFileManager _fileManager;
                std::string _savePath;
                std::shared_ptr<gameEngine::object::InputButton> _saveInput;
                std::unique_ptr<gameEngine::component::PopUp> _savePopUp;
                //here for test need to be in map after
                // game::objects::PowerUpTile _heelth()
                std::shared_ptr<game::objects::PowerUpTile> _healtTile;
            private:
                void setupCamera() noexcept;
        };
    }
}

#endif /* !PLAYSCENE_HPP_ */
