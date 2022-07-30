/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** main
*/

#include "main.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    try {
        Parser p(av[1]);
        p.parse();
        Algorithm alg(p.getAddrList());
        alg.loop();
    }
    catch (Done &d){
        return (0);
    }
    catch (Abort &a) {
        std::cerr << "Abort" << std::endl;
        return (0);
    }
    catch (BadInputException &b) {
        std::cerr << "BadInputException" << std::endl;
        return (84);
    }
    catch (NoSuchFileException &n) {
        std::cerr << "NoSuchFileException" << std::endl;
        return (84);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
