/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_
#include "Parser.hpp"

class Algorithm {
    public:
        Algorithm(Addressbook *addrList);
        void dump();
        void loop();
        ~Algorithm();
    private:
        Addressbook *addrList;
};

#endif /* !ALGORITHM_HPP_ */
