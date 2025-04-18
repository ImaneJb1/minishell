NAME = a.out

CC = cc

# CFLAGS = -Wall -Wextra -Werror
HEADER = globale_functions/global.h parsing/parsing.h
PRSING = parsing/fill_the_list.c  parsing/operations_condition.c  parsing/helpers.c parsing/enums.c
GAR_COLLECT = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c garbage_collector/ft_save_mem.c garbage_collector/mem_list.c
GLOBALE = globale_functions/ft_strchr.c globale_functions/ft_strlen.c globale_functions/globale.c globale_functions/join_str_char.c globale_functions/strcmp.c

SRC =  $(PRSING) $(GLOBALE) $(GAR_COLLECT)

OBJ = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)   $(OBJ) -o  $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re

.SECONDARY: $(OBJ)