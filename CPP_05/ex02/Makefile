RED_TWO = \033[1;32m
RED     = \033[5;32m
WHITE   = \033[1;37m
BLINK   = \033[5m
END     = \033[0m

NAME        = AForm
PROJECT     = CPP05 - ex02
CC          = c++
CFLAGS      = -std=c++98 -Wall -Wextra -Werror

INCLUDE     = -I./include
SRC_FILES   = main.cpp Bureaucrat.cpp Form.cpp
#add files i go hack
HEADER_FILES = include/Bureaucrat.hpp include/Form.hpp

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
