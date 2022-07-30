/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Address
*/

#ifndef ADDRESS_HPP_
    #define ADDRESS_HPP_

    #include <string>
    #include <vector>
    #include <iostream>
    #include <fstream>
    #include <sstream>

typedef enum {
    ALLEE,
    AVENUE,
    BOULEVARD,
    CHEMIN,
    IMPASSE,
    PLACE,
    QUAI,
    RUE,
    SQUARE
} Streettype;

class Address
{
private:
    std::vector<std::string> _street;
    std::vector<std::string> _city;
    Streettype type;
    unsigned int number;
    std::string _fullname;
public:
    Address(std::vector<std::string> city, unsigned int number, Streettype type, std::vector<std::string> street,  std::string fullname);
    std::string getFullName();
    void dump();
    bool cityHas(std::string input);
    std::string cityNth(std::string in, unsigned int n);
    std::vector<std::string> getCity();
    bool streetHas(std::string input);
    std::string streetNth(std::string in, unsigned int n);
    std::vector<std::string> getStreet();
    bool numberHas(std::string input);
    unsigned int getNumber();
    bool operator>(Address &other);
    ~Address();
};

#endif /* !ADDRESS_HPP_ */
