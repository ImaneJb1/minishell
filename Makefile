NAME = a.out

CC = cc

# CFLAGS = -Wall -Wextra -Werror
GARBAGE_COLLECTOR  = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c garbage_collector/ft_save_mem.c garbage_collector/mem_list.c 
PRSING = parsing/fill_the_list.c parsing/separate_with_one_space.c parsing/operations1.c parsing/operations2.c parsing/join_str_char.c \
parsing/globale.c parsing/ft_strlen.c parsing/ft_strchr.c parsing/linked_list_function.c

# GLOBALE = globale/ globale/ globale/strcmp.c globale/ globale/

SRC =  $(PRSING) $(GARBAGE_COLLECTOR)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS)   $(SRC) -o  $(NAME)

# clean:
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)