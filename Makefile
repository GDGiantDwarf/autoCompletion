##
## EPITECH PROJECT, 2022
## B-SYN-400-MPL-4-1-abstractVM-noe.sellam
## File description:
## Makefile
##

CC = g++

NAME = autoCompletion

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -W -Wall -Wextra -I./include

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
		rm -f $(OBJ)
