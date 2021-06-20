/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** LoadParser
*/

#ifndef LOADPARSER_HPP_
#define LOADPARSER_HPP_

#include "Errors.hpp"
#include <string>
#include "File.hpp"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "IInput.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Path.hpp"

namespace game {
    namespace systems {
        typedef struct playerInfo_s {
            std::string name = "";
            gameEngine::component::Transform tran;
            int lives = 0;
            Vector3T<float> speed;
            int score = 0;
        } playerInfo_t;

        class LoadParser {
            public:
                LoadParser(const std::string &saveName);
                ~LoadParser();

                gameEngine::component::Transform parseTransform(const std::string &pos, const std::string &rot, const std::string &scale);
                Vector3T<float> parseVector(const std::string &vec);
                std::string getInfo(const std::string &str);
                std::vector<playerInfo_t> loadPlayers();
                std::pair<std::vector<std::vector<int>>, std::string> loadMap();
            protected:
                std::vector<playerInfo_t> _players;
                Directory _dir;
                std::unique_ptr<Map> _map;
                std::vector<std::vector<int>> _tiles;
            private:
        };
    }
}

#endif /* !LOADPARSER_HPP_ */
