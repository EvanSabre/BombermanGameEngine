/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Utilitaries
*/

#include <vector>
#include <string>

std::vector<std::string> splitString(std::string & s, const char *splitter)
{
   size_t pos = 0;
   std::string delimiter (splitter);
   std::string token;
   std::vector<std::string> ret;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        ret.push_back(token);
    s.erase(0, pos + delimiter.length());
    }
    ret.push_back(s);
    return ret;
}