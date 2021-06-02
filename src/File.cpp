/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** File
*/


#include "File.hpp"

std::ostream& operator<<(std::ostream& out, const File &file)
{
    out << "File : " << file.getName() << " | at : " << file.getPath();
    out << "\n\tIs Accessible : " << file.isAccessible();
    return out;
}

File::File(const std::string &path)
{
    this->_path = path;
    if (this->isAccessible()) {
        this->_name = this->getNameFromPath(this->_path);
    } else {
        this->_name = this->_path;
    }
}

File::~File()
{
}

std::string File::getPath() const noexcept
{
    return this->_path;
}

std::string File::getName() const noexcept
{
    return this->_name;
}


//----------------

void File::create()
{
    if (this->isAccessible())
        return;

    std::ofstream new_file{this->_path};
}

bool File::isAccessible() const noexcept
{
    return (access(_path.c_str(), F_OK ) != -1 );
}


//-------------------

std::string File::read() const
{
    if (!isAccessible())
        throw std::runtime_error("Fiel : Is not accessible");
    std::ifstream file{this->_path};
    std::string content{};
    std::string buf{};

    if (file.is_open()) {
        while (getline (file, buf))
            content.append(buf + "\n");
    } else {
        throw std::runtime_error("Fiel : Is not accessible");
    }
    return content;
}

void File::clear() const
{
    if (!isAccessible())
        throw std::runtime_error("Fiel : Is not accessible");
    std::ofstream file{this->_path , std::ofstream::out | std::ofstream::trunc};
}

void File::write(const std::string &to_append) const
{
    if (!isAccessible())
        throw std::runtime_error("Fiel : Is not accessible");
    std::ofstream file{this->_path};
    file << to_append;
}

struct stat File::getStat() const
{
    if (!isAccessible())
        throw std::runtime_error("Fiel : Is not accessible");
    struct stat st;
    if (stat(this->_path.c_str(), &st) != 0)
        throw std::runtime_error("File : stat Failed");
    return st;
}


//-------------------

std::string File::getNameFromPath(const std::string &path) const noexcept
{
    size_t idx_last_slash = path.rfind("/");

    if (idx_last_slash == std::string::npos)
        idx_last_slash = -1;
    if (idx_last_slash == path.size() - 1)
        return getNameFromPath(path.substr(0, path.size() - 1));
    std::string name = path.substr(idx_last_slash + 1, path.size());
    return name;
}

bool File::compareConent(const File &file) const noexcept
{
    if (!isAccessible() || !file.isAccessible())
        return false;
    std::string content_one = this->read();
    std::string content_two = file.read();
    return (content_one == content_two);
}
