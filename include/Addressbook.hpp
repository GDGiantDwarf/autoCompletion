/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Addressbook
*/

#ifndef ADDRESSBOOK_HPP_
#define ADDRESSBOOK_HPP_
#include "Address.hpp"
#include <list>

typedef enum {
    CITY,
    STREET,
    NUMBER,
    FOUND
} SearchProgress;


class Addressbook {
    public:
        Addressbook();
        void push_back(Address *addr);
        void dump();
        int size();
        void search(std::string input);
        std::string getTotalInput();
        void citySearch();
        void citySelector();
        void streetSearch();
        void streetSelector();
        void showLikely();
        void autoComplete();
        std::list<Address *> getList() { return addrList; };
        std::string capitalize(std::string str);
        ~Addressbook();
        SearchProgress prog = CITY;
        bool skipsearch = false;
    private:
        std::list<Address *> addrList;
        std::vector<std::string> confirmed_city;
        std::vector<std::string> confirmed_street;
        std::string total_input;
        std::string to_str(std::vector<std::string> vec);
};

#endif /* !ADDRESSBOOK_HPP_ */
