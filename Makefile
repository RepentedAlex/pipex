NAME		= pipex

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror


SRC_DIR		= src/

SRC_FILES	= pipex.c \
				utils.c

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= ${SRC:.c=.o}

RM			= rm -rf
INCLUDE		= -I include

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
