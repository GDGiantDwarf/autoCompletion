/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Algorithm
*/

#include "Algorithm.hpp"
#include "Addressbook.hpp"

Algorithm::Algorithm(Addressbook *addrList)
{
    this->addrList = addrList;
}

void Algorithm::dump()
{
    addrList->dump();
}

void Algorithm::loop()
{
    while(addrList->prog != FOUND) {
        this->addrList->showLikely();
        std::string newInput;
        if (!addrList->skipsearch) {
            std::getline(std::cin, newInput);
            if(std::cin.eof())
                throw Done();
            if(newInput.length() != 1) {
                if(newInput == "ABORT")
                    throw Abort();
                throw BadInputException();
            }
            if(newInput[0] > 'A' && newInput[0] < 'Z')
                newInput[0] += 32;
            this->addrList->search(newInput);
        } else {
            addrList->skipsearch = false;
        }
        if(this->addrList->size() == 0)
            throw std::runtime_error("No address");
        this->addrList->autoComplete();
        if(this->addrList->prog == FOUND) {
            //std::cout << "Found" << std::endl;
            std::cout << "=> " << this->addrList->getList().front()->getFullName() << std::endl;
        }
    }
}

Algorithm::~Algorithm()
{
}
