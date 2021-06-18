
/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GAMEMANAGER
*/

#ifndef GAMEMANAGER_HPP_
#define GAMEMANAGER_HPP_


#include "IScene.hpp"
#include "UserManager.hpp"
#include "InputManager.hpp"
#include "WindowManager.hpp"
#include "SettingConf.hpp"

#define SETTINGS_MANAGER game::systems::SettingConf
#define SETTINGS game::system::setting_t

namespace game {
    namespace managers {
        class GameManager {
            public:
                GameManager(const std::string &str = "");
                ~GameManager();

                void setCurrentScene(const std::string &str);
                std::string getCurrentScene() const noexcept;
                void setQuit(bool q);

                bool haveToChange();
                bool haveToQuit();
                int nbPlayers = 1;
                int nbPlayersConfirmed = 0;
                int nbBots = 0;
                std::shared_ptr<game::managers::UserManager> _userManager;
                std::shared_ptr<gameEngine::managers::InputManager<game::Event>> _inputManager;

            protected:
                std::string _currentScene;
                bool _change = false;
                bool _quit = false;
                game::systems::setting_t _settings;
            private:
        };
    }
}

#endif /* !GAMEMANAGER_HPP_ */
