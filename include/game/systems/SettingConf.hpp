/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SettingConf
*/

#ifndef SETTINGCONF_HPP_
#define SETTINGCONF_HPP_

#include "Errors.hpp"
#include <string>
#include "File.hpp"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "KeyMap.hpp"

namespace game
{
    namespace systems
    {

        typedef struct s_settig {
            float _soundVolume;
            float _musicVolume;
            std::unordered_map<game::Event, std::pair<gameEngine::key_e, gameEngine::key_e>> _keyMap;
        } setting_t;

        class SettingConf;

        typedef setting_t (*parseFct_t)(setting_t conf, const std::string &key, std::string value);

        class SettingConf
        {
        public:
            static setting_t loadSetting(const std::string &filepath);

        private:
            static const std::unordered_map<std::string, parseFct_t> _parseFcts;
            static const std::unordered_map<std::string, game::Event> _eventMap;

        private:
            static setting_t getDefaultSettings() noexcept;
            static bool allSettingIsLoad(setting_t conf) noexcept;
            static void parseSetting(setting_t &conf, const std::vector<std::string> &file);

            static setting_t parseMusicVolume(setting_t conf, const std::string &key, std::string value);
            static setting_t parseSoundVolume(setting_t conf, const std::string &key, std::string value);


            static void parseInt(float &volume, std::string value);
            static setting_t parseKey(setting_t conf, const std::string &key, std::string value);

            static bool splitString(const std::string &ref, std::string &left, std::string &right, const std::string &sep);
        };
    } // namespace systems
} // namespace game

#endif /* !SETTINGCONF_HPP_ */
