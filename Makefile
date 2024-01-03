CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

NAME		= pipex

SRC_DIR		= src/
OBJ_DIR		= build/

SRC_FILES	= pipex.c

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= ${SRC:.c=.o}

RM			= rm -rf
INCLUDE		= -I include

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS)  $(OBJ) $(INCLUDE) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
