/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_
    #include "Address.hpp"
    #include <map>
    #include <list>
    #include "Error.hpp"
    #include <functional>
    #include <algorithm>
    #include "Addressbook.hpp"
    #define MAINREGEX "([a-zA-Zéèàùïô_ ]*),? ([\\d]+) (ALLEE|allée|AVENUE|BOULEVARD|CHEMIN|IMPASSE|PLACE|QUAI|RUE|SQUARE) ([a-zA-Zéèàùïô_ ]*)"


class Parser
{
private:
    std::vector<std::string> _lines;
    Addressbook *addrList;
    Address *makeAddress(std::string line);
    std::vector<std::string> tovect(std::string str);
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
public:
    Parser(char *dict_path);
    Addressbook *getAddrList();
    void parse();
    ~Parser();
};


#endif /* !PARSER_HPP_ */
