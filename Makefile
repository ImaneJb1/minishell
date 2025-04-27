NAME = mini

CC = cc

CFLAGS = -Wall -Wextra -Werror


GARBAGE_COLLECTOR = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c \
	garbage_collector/ft_save_mem.c garbage_collector/mem_list.c

HELPER_FUNCTIONS = helper_functions/delete_char_from_str.c helper_functions/delete_str_from_str.c \
	helper_functions/delete_str_len.c helper_functions/ft_str_join.c helper_functions/ft_strchr.c \
	helper_functions/ft_strdup.c helper_functions/ft_strlen.c helper_functions/insert_char_in_str.c \
	helper_functions/insert_str_in_str.c helper_functions/join_str_char.c  helper_functions/is_alpha.c \
	 helper_functions/is_digit.c helper_functions/separate_with_one_space.c helper_functions/strcmp.c \
	helper_functions/strncmp.c helper_functions/strnstr_index.c

PARSING_TOKEN_IDENTIFY = parsing/tokenizing/identify_types/all_enums.c parsing/tokenizing/identify_types/enums.c \
	parsing/tokenizing/identify_types/enums2.c parsing/tokenizing/identify_types/helpers.c \
	parsing/tokenizing/identify_types/identify_var.c

PARSING_TOKEN_SPLIT = parsing/tokenizing/spliting/fill_the_list.c parsing/tokenizing/spliting/is_argument.c \
	parsing/tokenizing/spliting/is_pipe_variable.c parsing/tokenizing/spliting/is_quotes.c \
	parsing/tokenizing/spliting/redirections_heredoc.c

PARSING_SYNTAX = parsing/syntax_error/check_valid_syntax.c parsing/syntax_error/handling_pipes.c \
	parsing/syntax_error/unclosed_quotes.c parsing/syntax_error/printers.c parsing/syntax_error/special_tokens.c

PARSING_ENV =  parsing/environment/get_vriable_value.c parsing/environment/variable_checkers.c

PARSING_LL = linked_list_function/t_cmd_linked_list1.c linked_list_function/t_cmd_linked_list_2.c \
	linked_list_function/t_env_linked_list.c

PARSING = parsing/parsing.c parsing/globale.c $(PARSING_TOKEN_IDENTIFY) $(PARSING_TOKEN_SPLIT) $(PARSING_SYNTAX) \
	$(PARSING_ENV) $(PARSING_LL)

BUILT_IN_ENV = built_ins/env/creat_environment.c

BUILT_IN = $(BUILT_IN_ENV)

SRC = minishell.c $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PARSING) $(BUILT_IN)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)


































# NAME = a.out

# CC = cc

# # CFLAGS = -Wall -Wextra -Werror

# # Source directories
# GARBAGE_COLLECTOR = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c garbage_collector/ft_free.c \
# 	garbage_collector/ft_save_mem.c garbage_collector/mem_list.c

# # Helper functions (explicit list, no wildcards)
# HELPER_FUNCTIONS = helper_functions/delete_char_from_str.c helper_functions/delete_str_from_str.c \
# 	helper_functions/delete_str_len.c helper_functions/ft_str_join.c helper_functions/ft_strchr.c \
# 	helper_functions/ft_strdup.c helper_functions/ft_strlen.c helper_functions/insert_char_in_str.c \
# 	helper_functions/insert_str_in_str.c helper_functions/join_str_char.c \
# 	helper_functions/separate_with_one_space.c helper_functions/strcmp.c \
# 	helper_functions/strncmp.c helper_functions/strnstr_index.c

# # parsing sources
# PARSING_MISC = parsing/parsing.c parsing/globale.c

# PARSING_TOKEN_IDENTIFY = parsing/tokenizing/identify_types/all_enums.c parsing/tokenizing/identify_types/enums.c \
# 	parsing/tokenizing/identify_types/enums2.c parsing/tokenizing/identify_types/helpers.c \
# 	parsing/tokenizing/identify_types/identify_var.c

# PARSING_TOKEN_SPLIT = parsing/tokenizing/spliting/fill_the_list.c parsing/tokenizing/spliting/is_argument.c \
# 	parsing/tokenizing/spliting/is_pipe_variable.c parsing/tokenizing/spliting/is_quotes.c \
# 	parsing/tokenizing/spliting/redirections_heredoc.c

# PARSING_SYNTAX = parsing/syntax_error/check_valid_syntax.c parsing/syntax_error/handling_pipes.c \
# 	parsing/syntax_error/unclosed_quotes.c parsing/syntax_error/printers.c parsing/syntax_error/special_tokens.c

# PARSING_ENV = parsing/environment/creat_environment.c parsing/environment/get_vriable_value.c parsing/environment/variable_checkers.c

# PARSING_LL = parsing/linked_list_function/t_cmd_linked_list1.c parsing/linked_list_function/t_cmd_linked_list_2.c \
# 	parsing/linked_list_function/t_env_linked_list.c

# # aggregate parsing
# PARSING = $(PARSING_MISC) $(PARSING_TOKEN_IDENTIFY) $(PARSING_TOKEN_SPLIT) $(PARSING_SYNTAX) $(PARSING_ENV) $(PARSING_LL)

# # all source files
# SRC = $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PARSING)

# OBJ = $(SRC:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .SECONDARY: $(OBJ)
