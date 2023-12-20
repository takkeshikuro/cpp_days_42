RED_TWO = \033[1;32m
RED     = \033[5;32m
WHITE   = \033[1;37m
BLINK   = \033[5m
END     = \033[0m

NAME        = Brain
PROJECT     = CPP04 - ex01
CC          = c++
CFLAGS      = -std=c++98 -Wall -Wextra -Werror
INCLUDE     = -I./include
SRC_FILES   = main.cpp Animal.cpp Cat.cpp Dog.cpp \
			  WrongAnimal.cpp WrongCat.cpp Brain.cpp

HEADER_FILES = include/Animal.hpp include/Cat.hpp include/Brain.hpp \
			   include/Dog.hpp include/WrongAnimal.hpp include/WrongCat.hpp

OBJS_DIR    = .objets
OBJS        = $(SRC_FILES:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@printf "$(RED_TWO)$(PROJECT) compilation [ok]\n"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS): $(OBJS_DIR)/%.o: %.cpp $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
