/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Addressbook
*/

#include "Addressbook.hpp"
#include <algorithm>
#include <map>
#include "Error.hpp"

Addressbook::Addressbook()
{
}

void Addressbook::push_back(Address *addr)
{
    addrList.push_back(addr);
}

int Addressbook::size()
{
    return addrList.size();
}

void Addressbook::dump()
{
    for (auto it : addrList)
        it->dump();
}

void Addressbook::search(std::string input)
{
    this->total_input += input;
    if (this->prog == CITY)
        return citySearch();
    if (this->prog == STREET)
        return streetSearch();
    if (this->prog == FOUND)
        std::cout << "Found" << std::endl;
}

void Addressbook::citySearch()
{
    addrList.erase(std::remove_if(addrList.begin(), addrList.end(),
            [&](Address *adr)-> bool { return !adr->cityHas(this->total_input); }),
            addrList.end());
}

void Addressbook::streetSearch()
{
    addrList.erase(std::remove_if(addrList.begin(), addrList.end(),
            [&](Address *adr)-> bool { return !adr->streetHas(this->total_input); }),
            addrList.end());
}

void Addressbook::showLikely()
{
    std::vector<std::pair<char, int*>> table;
    int pos = total_input.length();
    std::string chars;
    bool should_new_entry;
    for (auto it : addrList) {
        chars = prog == CITY ? it->cityNth(total_input, pos) : it->streetNth(total_input, pos);
        for (auto c : chars) {
            should_new_entry = true;
            for (auto pair : table) {
                if (pair.first == c) {
                    *pair.second = *pair.second + 1;
                    should_new_entry = false;
                    break;
                }
            }
            if (should_new_entry)
                table.push_back(std::make_pair(c, new int(1)));
        }
    }
    std::sort(table.begin(), table.end(),
            [](std::pair<char, int*> a, std::pair<char, int*> b)-> bool {
                bool res = *a.second > *b.second;
                if (*a.second == *b.second) {
                    res = a.first < b.first;
                }
                return res;
            });
    if(table.size() == 1) {
        this->total_input += table[0].first;
        return this->showLikely();
    }
    for (unsigned int i = 0; i < 5 && i < table.size(); i++) {
        std::cout << "{" << this->capitalize(this->to_str(this->confirmed_city))
        << (this->confirmed_city.size() != 0 ? ", " : "") << this->capitalize(this->total_input)
        << table[i].first << "}" <<((i == 4 || i == table.size() - 1) ? "\n" : " ");
    }
    if (table.size() == 0 && this->addrList.size() != 0) {
        this->prog == CITY ? this->citySelector() : this->streetSelector();
    }
}

void Addressbook::citySelector()
{
    int i = 1;
    std::string selectstr;
    int selection;
    std::map<int, Address *> city_list;
    for (auto it : addrList) {
        if(std::none_of(city_list.begin(), city_list.end(),
                [&](std::pair<int, Address *> pair)-> bool {
                    return this->to_str(pair.second->getCity()) == this->to_str(it->getCity());
                }))
            city_list[i++] = it;
    }
    for (int j = 1; j < i; j++) {
        std::cout << "{" << j << " : " << this->to_str(city_list[j]->getCity()) << "}" << ((j == i - 1) ? "\n" : " ");
    }

    std::getline(std::cin, selectstr);
    selection = std::stoi(selectstr);
    if (selection > i || selection < 1)
        throw BadInputException();
    this->confirmed_city = city_list[selection]->getCity();
    this->prog = STREET;
    this->total_input = "";
    this->skipsearch = true;
    this->addrList.erase(std::remove_if(addrList.begin(), addrList.end(),
            [&](Address *adr)-> bool { return adr->getCity() != this->confirmed_city; }),
            addrList.end());
}

void Addressbook::streetSelector()
{
    int i = 1;
    std::string selectstr;
    int selection;
    std::map<int, Address *> city_list;
    for (auto it : addrList) {
        if(std::none_of(city_list.begin(), city_list.end(),
                [&](std::pair<int, Address *> pair)-> bool {
                    return (pair.second->getFullName()) == (it->getFullName());
                }))
            city_list[i++] = it;
    }
    for (int j = 1; j < i; j++) {
        std::cout << "{" << j << " : " << (city_list[j]->getFullName()) << "}" << ((j == i - 1) ? "\n" : " ");
    }

    std::getline(std::cin, selectstr);
    selection = std::stoi(selectstr);
    if (selection > i || selection < 1)
        throw BadInputException();
    std::cout << "=> " <<city_list[selection]->getFullName() << std::endl;
    throw Done();
}

void Addressbook::autoComplete()
{
    if (prog == CITY && std::all_of(addrList.begin(), addrList.end(),
            [&](Address *adr)-> bool {
                return adr->getCity() == addrList.front()->getCity();
            })) {
                this->total_input = "";
                this->prog = STREET;
                this->confirmed_city = addrList.front()->getCity();
            }
    if (prog == STREET && std::all_of(addrList.begin(), addrList.end(),
            [&](Address *adr)-> bool {
                return adr->getStreet() == addrList.front()->getStreet();
            })) {
                this->total_input = "";
                this->prog = NUMBER;
                this->confirmed_street = addrList.front()->getStreet();
            }
    if (addrList.size() == 1) {
        this->total_input = "";
        this->prog = FOUND;
    }
}

std::string Addressbook::getTotalInput()
{
    return this->total_input;
}

std::string Addressbook::to_str(std::vector<std::string> vec)
{
    std::string res = "";
    for (auto it : vec)
        res += it + (it == vec.back() ? "" : " ");
    return res;
}

std::string Addressbook::capitalize(std::string str)
{
    std::string res = "";
    for (auto it : str)
        res += std::toupper(it);
    return res;
}

Addressbook::~Addressbook()
{

}
