/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SettingConf
*/

#include "SettingConf.hpp"

using namespace game::systems;

#define MUSIC_VOLUME_KEY "MUSIC-VOLUME"
#define SOUND_VOLUME_KEY "SOUND-VOLUME"
#define MOVE_UP_KEY "UP"
#define MOVE_DOWN_KEY "DOWN"
#define MOVE_LEFT_KEY "LEFT"
#define MOVE_RIGHT_KEY "RIGHT"
#define VALIDE_DROP_KEY "VALIDATE/DROPBOMB"

#define PARAMS_SEP ","
#define KEY_VALUE_SEP ":"

const std::unordered_map<std::string, parseFct_t> SettingConf::_parseFcts = {
    {MUSIC_VOLUME_KEY, &SettingConf::parseMusicVolume},
    {SOUND_VOLUME_KEY, &SettingConf::parseSoundVolume},
    {MOVE_UP_KEY, &SettingConf::parseKey},
    {MOVE_DOWN_KEY, &SettingConf::parseKey},
    {MOVE_LEFT_KEY, &SettingConf::parseKey},
    {MOVE_RIGHT_KEY, &SettingConf::parseKey},
    {VALIDE_DROP_KEY, &SettingConf::parseKey},
};

const std::unordered_map<std::string, game::Event> SettingConf::_eventMap = {
    {MOVE_UP_KEY, game::MOVE_UP},
    {MOVE_DOWN_KEY, game::MOVE_DOWN},
    {MOVE_LEFT_KEY, game::MOVE_LEFT},
    {MOVE_RIGHT_KEY, game::MOVE_RIGHT},
    {VALIDE_DROP_KEY, game::VALIDATE},
};

//------------------

setting_t SettingConf::loadSetting(const std::string &filepath)
{
    setting_t setting = getDefaultSettings();
    std::vector<std::string> file_content{""};

    try {
        File file(filepath);
        file_content = file.readLines();
    } catch(const std::exception &e) {
        // std::string msg = e.what();
        //throw ConfigError("Configuration File : ");
        std::cerr << e.what() << std::endl;
        throw e;
    }

    try {
        parseSetting(setting, file_content);
    } catch(const IndieError &e) {
        throw e;
    }
    if (!allSettingIsLoad(setting))
        throw ConfigError("Missing configuration parameter ");
    return setting;
}

setting_t SettingConf::getDefaultSettings() noexcept
{
    setting_t conf;
    conf._musicVolume = -1;
    conf._soundVolume = -1;
    conf._keyMap = {
        {game::MOVE_UP, {gameEngine::KEY_NULL, gameEngine::KEY_NULL}},
        {game::MOVE_DOWN, {gameEngine::KEY_NULL, gameEngine::KEY_NULL}},
        {game::MOVE_LEFT, {gameEngine::KEY_NULL, gameEngine::KEY_NULL}},
        {game::MOVE_RIGHT, {gameEngine::KEY_NULL, gameEngine::KEY_NULL}},
        {game::VALIDATE, {gameEngine::KEY_NULL, gameEngine::KEY_NULL}},
    };
    return conf;
}

bool SettingConf::allSettingIsLoad(setting_t conf) noexcept
{
    setting_t ref = getDefaultSettings();

    if (ref._musicVolume == conf._musicVolume
        || ref._soundVolume == conf._soundVolume
    ) {
        return false;
    }
    for (const std::pair<game::Event, std::pair<gameEngine::key_e, gameEngine::key_e>> &it: conf._keyMap ) {
        if (it.second.first == gameEngine::KEY_NULL || it.second.second == gameEngine::KEY_NULL)
            return false;
    }
    return true;
}

void SettingConf::parseSetting(setting_t &conf, const std::vector<std::string> &file)
{
    for (const auto &line : file) {
        std::string key{""};
        std::string value{""};

        try {
            splitString(line, key, value, KEY_VALUE_SEP);
        } catch(const std::exception& e) {
            std::string msg = e.what();
            throw ConfigError("Parsing error " + msg);
        }
        value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());

        try {
            conf = _parseFcts.at(key)(conf, key, value);
        } catch(const std::exception &e) {
            std::string msg = e.what();
            throw ConfigError("Parsing Error " + msg);
        }
    }
}


//-----------------------------

//map function

setting_t SettingConf::parseMusicVolume(setting_t conf, const std::string &key, std::string value)
{
    try {
        parseInt(conf._musicVolume, value);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw e;
    }
    return conf;
}

setting_t SettingConf::parseSoundVolume(setting_t conf, const std::string &key, std::string value)
{
    try {
        parseInt(conf._soundVolume, value);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw e;
    }
    return conf;
}

//--------------------------

//parse function

void SettingConf::parseInt(float &volume, std::string value)
{
    float buf = 0;

    try {
        buf = std::stof(value.c_str());
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw e;
    }
    volume = buf;
}

setting_t SettingConf::parseKey(setting_t conf, const std::string &key, std::string value)
{
    std::string keyboard{""};
    std::string gamepad{""};
    gameEngine::key_e board_key = gameEngine::KEY_NULL;
    gameEngine::key_e pad_key = gameEngine::KEY_NULL;

    try {
        if (!splitString(value, keyboard, gamepad, PARAMS_SEP))
            throw ConfigError("Key parsing");
    } catch(const ConfigError &e) {
        throw e;
    }
    try {
        board_key = (gameEngine::key_e)std::stoi(keyboard);
        pad_key = (gameEngine::key_e)std::stoi(gamepad);
    } catch(const std::exception& e) {
        throw ConfigError("Key Parsing: argument not convertible to int");
    }


    try {
        conf._keyMap.at(_eventMap.at(key)) = std::pair<gameEngine::key_e, gameEngine::key_e>(board_key, pad_key);
    } catch(const std::exception& e) {
        std::string msg = e.what();
         throw ConfigError("Parsing Key : " + msg);
    }
    return conf;
}

bool SettingConf::splitString(const std::string &ref, std::string &left, std::string &right, const std::string &sep)
{
    std::size_t idx =  ref.find(sep);

    if (idx == std::string::npos)
        throw ConfigError("Missing separator " + sep);
    left = ref.substr(0, idx);
    right = ref.substr(idx + 1, ref.length() - idx);
    if (left.empty() || right.empty())
        return false;
    return true;
}