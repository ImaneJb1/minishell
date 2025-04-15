NAME = pipex
BONUS_NAME = /tmp/.bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

GET = ./get_next_line/get_next_line_bonus.c
GET_UTILS = ./get_next_line/get_next_line_utils_bonus.c

SOURCES = pipex.c errors.c join_dup_cmp.c ft_substr.c ft_split.c close_and_dup.c initialize.c wait_function.c \
path_functions.c creat_fd.c execute_cmd.c put_str.c ft_strlen.c

SOURCES_BONUS = pipex_bonus.c $(GET) $(GET_UTILS) join_dup_cmp_bonus.c ft_substr_bonus.c ft_split_bonus.c ft_strlen_bonus.c \
initialize_bonus.c creat_fd_bonus.c get_full_cmd_bonus.c path_functions_bonus.c childs_bonus.c close_pipes_bonus.c \
allocat_pipes_and_pid_bonus.c dup_and_close_bonus.c wait_function_bonus.c free_and_errors_bonus.c  here_doc_bonus.c

OBJ = $(SOURCES:.c=.o)

OBJ_BONUS = $(SOURCES_BONUS:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS)  $(OBJ_BONUS) -o $(NAME)
	touch $(BONUS_NAME)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean all

.SECONDARY: BONUS_NAME OBJ