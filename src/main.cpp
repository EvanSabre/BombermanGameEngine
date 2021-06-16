/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** main
*/

#include <memory>
#include "GlobalManager.hpp"
#include "SettingConf.hpp"

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920

int main()
{
    game::managers::GlobalManager manager;
    game::systems::setting_t conf;


    try
    {
        conf = game::systems::SettingConf::loadSetting("./setting.conf");
    }
    catch(const std::exception &e)
    {
        return 84;
    }


    try {
        manager.run();
    } catch (IndieError &e) {
        std::cerr << "Failed to load a scene" << std::endl;
        return 84;
    }
    return 0;
}
