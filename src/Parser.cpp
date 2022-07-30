/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Parser
*/

#include "Parser.hpp"
#include <algorithm>
#include <regex>

Parser::Parser(char *dict_path)
{
    std::ifstream file(dict_path);
    std::string line;

    if (!file)
        throw NoSuchFileException();
    while(std::getline(file, line))
    {
        _lines.push_back(line);
    }
    this->addrList = new Addressbook();
}

void Parser::parse()
{
    Address *address = NULL;
    // for (auto it : _lines) {
    //     std::cout << it << std::endl;
    // }
    for (auto it : _lines) {
        address = this->makeAddress(it);
        if (address != NULL) {
            this->addrList->push_back(address);
        } else {
            std::cerr << it << std::endl;
        }
    }
}

Address *Parser::makeAddress(std::string line)
{
    std::regex pattern(MAINREGEX, std::regex_constants::icase);
    std::smatch cmd;
    std::string linecp = line;
    line.erase(remove(line.begin(), line.end(), '\''), line.end());
    line.erase(remove(line.begin(), line.end(), '-'), line.end());

    if (!std::regex_match(line, cmd, pattern)) {
        //std::cout << "Error: " << line << std::endl;
        return NULL; //todo error correction
    }
    //std::cout << "Parsing: " << line << std::endl;
    return new Address(this->tovect(cmd[1]), std::stoi(cmd[2]), this->typemap.at(cmd[3]), this->tovect(cmd[4]), linecp);
}

std::vector<std::string> Parser::tovect(std::string str)
{
    std::vector<std::string> vec;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        std::transform(token.begin(), token.end(), token.begin(),
        [](unsigned char c){ return std::tolower(c); });
        vec.push_back(token);
    }
    return vec;
}

Addressbook *Parser::getAddrList()
{
    return addrList;
}

Parser::~Parser()
{
}
