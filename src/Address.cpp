/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Address
*/

#include "Address.hpp"
#include <map>

Address::Address(std::vector<std::string> city, unsigned int number, Streettype type, std::vector<std::string> street,  std::string fullname)
{
    this->_street = street;
    this->_city = city;
    this->number = number;
    this->type = type;
    this->_fullname = fullname;
}

std::string Address::getFullName()
{
    return _fullname;
}

void Address::dump()
{
    const std::map<std::string, Streettype> typemap = {
        {"allée", ALLEE},
        {"avenue", AVENUE},
        {"boulevard", BOULEVARD},
        {"chemin", CHEMIN},
        {"impasse", IMPASSE},
        {"place", PLACE},
        {"quai", QUAI},
        {"rue", RUE},
        {"square", SQUARE}
};
    std::cout << "Address: " << _fullname << std::endl;
    std::cout << "City: [";
    for(auto it : _city)
        std::cout << it << " ";
    std::cout << "]" << std::endl;
    std::cout << "Number: [" << number << "]" << std::endl;
    std::cout << "Type: [";
    for (auto it : typemap)
        if (it.second == type) {
            std::cout << it.first << " ";
            break;
        }
    std::cout << "]" << std::endl;
    std::cout << "Street: [";
    for(auto it : _street)
        std::cout << it << " ";
    std::cout << "]" << std::endl;
}

bool Address::operator>(Address &other)
{
    return (this->_fullname > other._fullname);
}

bool Address::cityHas(std::string input)
{
    for(auto it : _city)
        if(it.substr(0, input.length()) == input)
            return true;
    return false;
}

std::string Address::cityNth(std::string in, unsigned int n)
{
    std::string res = "";
    for (unsigned int i = 0; i < _city.size(); i++){
        if (_city[i].length() > n && _city[i].substr(0, n) == in) {
            res += _city[i][n];
        }
    }
    return res;
}

bool Address::streetHas(std::string input)
{
    for(auto it : _street)
        if(it.substr(0, input.length()) == input)
            return true;
    return false;
}

std::string Address::streetNth(std::string in, unsigned int n)
{
    std::string res = "";
    for (unsigned int i = 0; i < _street.size(); i++){
        if (_street[i].length() > n && _street[i].substr(0, n) == in) {
            res += _street[i][n];
        }
    }
    return res;
}

bool Address::numberHas(std::string input)
{
    std::string nbstr = std::to_string(number);
    if(nbstr.substr(0, input.length()) == input)
        return true;
    return true;
}

std::vector<std::string> Address::getCity()
{
    return _city;
}

std::vector<std::string> Address::getStreet()
{
    return _street;
}

Address::~Address()
{
}
