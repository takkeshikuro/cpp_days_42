RED_TWO = \033[1;32m
RED     = \033[5;32m
WHITE   = \033[1;37m
BLINK   = \033[5m
END     = \033[0m

NAME        = BJR
PROJECT     = CPP01 - ex02
CC          = c++
CFLAGS      = -g3 -Wall -std=c++98 -Wextra -Werror

INCLUDE     = -I./include
SRC_FILES   = main.cpp

OBJS_DIR    = .objets
OBJS        = $(SRC_FILES:%.cpp=$(OBJS_DIR)/%.o)

# MAKEFILE 

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@printf "$(RED_TWO)$(PROJECT) compilation [ok]\n"
	
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Utilisez -MMD pour générer des fichiers de dépendance
$(OBJS): $(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

-include $(OBJS:.o=.d) # Inclure les fichiers de dépendance

.PHONY: all clean fclean re
