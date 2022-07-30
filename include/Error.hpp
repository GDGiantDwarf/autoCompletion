/*
** EPITECH PROJECT, 2022
** B-SYN-400-MPL-4-1-autoCompletion-noe.sellam
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_
    #include <typeinfo>
    #include <exception>

class NoSuchFileException : public std::exception {
    public:
    char * what () {
        return (char *) "NoSuchFileException";
    }
};

class Abort : public std::exception {
    public:
    char * what () {
        return (char *) "Abort";
    }
};

class Done : public std::exception {
    public:
    char * what () {
        return (char *) "Done";
    }
};

class BadInputException : public std::exception {
    public:
    char * what () {
        return (char *) "BadInputException";
    }
};

#endif /* !ERROR_HPP_ */
