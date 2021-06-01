/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** JsonParser
*/

#ifndef JSONPARSER_HPP_
#define JSONPARSER_HPP_

#include <boost/json.hpp>
#include <iomanip>
#include <iostream>

class JsonParser
{
    public:
        JsonParser();
        ~JsonParser();
        boost::json::value parse_file( char const* filename);
        void pretty_print( std::ostream& os, boost::json::value const& jv, std::string* indent = nullptr);
    private:
};

#endif /* !JSONPARSER_HPP_ */
