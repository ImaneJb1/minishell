NAME = a.out

CC = cc

CFLAGS = -Wall -Wextra -Werror

PRSING = parsing/fill_the_list.c parsing/ parsing/separate_with_one_space.c parsing/operations_condition.c  parsing/ 

GLOBALE = globale/ft_strchr.c globale/ft_strlen.c globale/strcmp.c globale/globale.c globale/join_str_char.c

SRC =  $(PRSING) $(GLOBALE)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)   $(OBJ) -o  $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)