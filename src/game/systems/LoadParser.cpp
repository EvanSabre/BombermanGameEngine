/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** LoadParser
*/

#include "LoadParser.hpp"

using namespace game::systems;
#define SEPERATOR "####"

LoadParser::LoadParser(const std::string &saveName) :
_dir(realpath(std::string("./Saves/" + saveName).c_str(), NULL), false)
{

}

LoadParser::~LoadParser()
{
}

gameEngine::component::Transform LoadParser::parseTransform(const std::string &pos, const std::string &rot, const std::string &scale)
{
    gameEngine::component::Transform t;

    std::cout << pos << rot << scale << std::endl;
    if (pos.find("Pos") == pos.npos || rot.find("Rotation") == rot.npos || scale.find("Scale") == scale.npos)
        throw SaveError("Player save File transform is wrong");
    t.setPosition(parseVector(pos.substr(pos.find('{'))));
    t.setRotation(parseVector(rot.substr(rot.find('{'))));
    t.setScale(parseVector(scale.substr(scale.find('{'))));
    return t;
}

std::string LoadParser::getInfo(const std::string &str)
{
    size_t pos = str.find(':');
    std::string res;

    if (pos == str.npos)
        return std::string("");
    res = str.substr(pos + 1);
    res.erase(std::remove_if(res.begin(), res.end(), ::isspace), res.end());
    return res;
}

bool isVecChar(unsigned int i)
{
    if (i =='{' || i == '}')
        return true;
    return false;
}

Vector3T<float> LoadParser::parseVector(const std::string &vec)
{
    std::string token;
    std::string copy = vec;
    size_t pos = 0;
    char delim = ',';
    std::vector<float> valueArr;

    if (vec[vec.size() - 1] == '\n')
        copy.pop_back();
    if (copy[0] != '{' || copy[copy.size() - 1] != '}') {
        throw SaveError("Player save File is wrong");
    }
    while ((pos = copy.find(delim)) != copy.npos) {
        token = copy.substr(0, pos);
        copy.erase(0, pos + 1);
        token.erase(std::remove_if(token.begin(), token.end(), isVecChar), token.end());
        std::cout << token << std::endl;
        valueArr.push_back(atof(token.c_str()));
    }
    valueArr.push_back(atof(copy.c_str()));
    if (valueArr.size() != 3) {
        std::cout << "Player save file Vectorsd are wrong\n";
        throw SaveError("Player save file Vectors are wrong\n");
    }
    std::cout << valueArr[0] << std::endl;
    return Vector3T<float>(valueArr[0], valueArr[1], valueArr[2]);
}

std::vector<playerInfo_t> LoadParser::loadPlayers()
{
    File f = _dir.loadFile("Players.save", false);
    std::vector<std::string> text = f.readLines();
    playerInfo_t info;

    for (auto line = text.begin(); line < text.end(); line++) {
        line->pop_back();
        if (*line != SEPERATOR) {
            if (line->find("Player") != line->npos) {
                info.name = getInfo(*line);
            }
            if (line->find("Transform") != line->npos) {
                info.tran = parseTransform(*line, *(line + 1), *(line + 2));
                line += 2;
                continue;
            }
            if (line->find("Lives") != line->npos) {
                info.lives = atoi(getInfo(*line).c_str());
            }
            if (line->find("Speed") != line->npos) {
                info.speed = parseVector(getInfo(*line));
            }
            if (line->find("Score") != line->npos) {
                info.score = atoi(getInfo(*line).c_str());
            }
        } else {
            _players.push_back(info);
        }
    }
    return _players;
}

Map LoadParser::loadMap()
{
    File f = _dir.loadFile("MapSave.save", false);
    std::vector<std::string> text = f.readLines();
    std::string tmp;
    std::vector<int> line;
    std::size_t size = atoi(text[1].c_str());
    std::string universe = text[0];

    if (size == 0) {
        throw LoadingError("Could not load map from save no size");
    }
    universe.pop_back();
    if (universe != "Samurai" && universe != "Vikings" && universe != "Pirates") {
        universe = "Samurai";
    }
    text.erase(text.begin());
    text.erase(text.begin());
    for (auto i : text) {
        for (std::string::size_type j = 0; j != i.size(); j++) {
            if (i[j] == '|') {
                line.push_back(atoi(tmp.c_str()));
                tmp.erase();
            } else
                tmp.push_back(i[j]);
        }
        _tiles.push_back(line);
        line.clear();
    }
    return Map(universe, _tiles, size);
}
