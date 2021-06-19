
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
#define UNIVERSE std::array<std::string, 3>({"Pirates", "Samurai", "Vikings"})

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
                std::string getUniverse() const noexcept;
                void setUniverse(const std::string &uni);

                std::vector<std::shared_ptr<game::User>> getPlayers() const noexcept;
                void pushPlayer(std::shared_ptr<game::User> &player);
                int nbPlayers = 4;
                int nbPlayersConfirmed = 0;
                int nbBots = 0;
                std::shared_ptr<game::managers::UserManager> _userManager;
                std::shared_ptr<gameEngine::managers::InputManager<game::Event>> _inputManager;
                std::vector<std::shared_ptr<game::User>> _players;

                void setMusicVolume(float volume);
                float getMusicVolume() const;
                void setSoundVolume(float volume);
                float getSoundVolume() const;

            protected:
                std::string _currentScene;
                bool _change = false;
                bool _quit = false;
                game::systems::setting_t _settings;
                float _musicVolume;
                float _soundVolume;

                std::string _universe = "Viking";
            private:
        };
    }
}

#endif /* !GAMEMANAGER_HPP_ */
