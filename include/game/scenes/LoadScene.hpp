/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** LoadScene
*/

#ifndef LOADSCENE_HPP_
#define LOADSCENE_HPP_

#include "AScene.hpp"
#include "Errors.hpp"
#include "File.hpp"
#include "BSdf.hpp"
#include "Selector.hpp"

namespace game {
    namespace scenes {
        class LoadScene : public gameEngine::AScene {
            public:
                LoadScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~LoadScene();

                void start() override;
                void update() override;
                void draw() override;
                std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> initDefault();
                std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> loadSaves();
            private:
                std::unique_ptr<gameEngine::component::Selector> _saveSelector = nullptr;
                gameEngine::managers::AFileManager _fileManager;
                gameEngine::encapsulation::BTexture2D _background;
                bool _canSave;
        };
    }
}

#endif /* !LOADSCENE_HPP_ */
