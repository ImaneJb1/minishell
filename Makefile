NAME = mini

CC = cc
# CFLAGS = -Wall -Wextra -Werror

# ===================== GARBAGE COLLECTOR =====================
GARBAGE_COLLECTOR = garbage_collector/ft_calloc.c garbage_collector/ft_exit.c \
	garbage_collector/ft_free.c garbage_collector/ft_save_mem.c \
	garbage_collector/mem_list.c

# ===================== HELPER FUNCTIONS ======================
HELPER_FUNCTIONS = helper_functions/delete_char_from_str.c helper_functions/delete_str_from_str.c \
	helper_functions/delete_str_len.c helper_functions/ft_str_join.c helper_functions/ft_strchr.c \
	helper_functions/ft_strdup.c helper_functions/ft_strlen.c helper_functions/insert_char_in_str.c \
	helper_functions/insert_str_in_str.c helper_functions/join_str_char.c helper_functions/is_alpha.c \
	helper_functions/is_digit.c helper_functions/separate_with_one_space.c helper_functions/strcmp.c \
	helper_functions/strncmp.c helper_functions/strnstr_index.c helper_functions/free_2d_array.c

# ===================== PARSING ===============================
PARSING_TOKEN_IDENTIFY = parsing/tokenizing/identify_types/all_enums.c parsing/tokenizing/identify_types/enums.c \
	parsing/tokenizing/identify_types/enums2.c parsing/tokenizing/identify_types/helpers.c \
	parsing/tokenizing/identify_types/identify_var.c

PARSING_TOKEN_SPLIT = parsing/tokenizing/spliting/fill_the_cmd_list.c parsing/tokenizing/spliting/is_argument.c \
	parsing/tokenizing/spliting/is_pipe_variable.c parsing/tokenizing/spliting/is_quotes.c \
	parsing/tokenizing/spliting/redirections_heredoc.c

PARSING_SYNTAX = parsing/syntax_error/is_valid_syntax.c parsing/syntax_error/handling_pipes.c \
	parsing/syntax_error/unclosed_quotes.c parsing/syntax_error/printers.c parsing/syntax_error/special_tokens.c \
	parsing/syntax_error/heredoc_error.c

PARSING_ENV = parsing/environment/get_vriable_value.c parsing/environment/variable_checkers.c

PARSING_REDIR = parsing/redirections/append.c parsing/redirections/fill_fd_into_exec.c \
	parsing/redirections/redir_in.c parsing/redirections/redir_out.c

PARSING_LL = linked_list_function/t_cmd_linked_list1.c linked_list_function/t_cmd_linked_list_2.c \
	linked_list_function/t_env_linked_list1.c linked_list_function/t_env_linked_list2.c \
	linked_list_function/t_exec_linked_list1.c linked_list_function/t_exec_linked_list2.c \
	linked_list_function/t_pipe_linked_list1.c linked_list_function/t_pipe_linked_list2.c

PARSING = parsing/parsing.c parsing/remove_quotes.c parsing/fill_the_exec_list.c $(PARSING_TOKEN_IDENTIFY) \
	$(PARSING_TOKEN_SPLIT) $(PARSING_SYNTAX) $(PARSING_ENV) $(PARSING_LL) $(PARSING_REDIR)

# ===================== BUILTINS ==============================
BUILT_IN_ENV = built_ins/env/creat_environment.c
BUILT_IN_EXPORT = built_ins/export/export_function.c built_ins/export/export_check_functions.c
BUILT_IN_UNSET = built_ins/unset/new_unset.c
BUILT_IN_ECHO = built_ins/echo/echo.c
BUILT_IN_PWD = built_ins/pwd/pwd.c
BUILT_IN_CD = built_ins/cd/cd.c built_ins/cd/change_oldpwd.c built_ins/cd/change_pwd.c built_ins/cd/special_cases.c

BUILT_IN = $(BUILT_IN_ENV) $(BUILT_IN_EXPORT) $(BUILT_IN_UNSET) $(BUILT_IN_ECHO) $(BUILT_IN_PWD) $(BUILT_IN_CD)

# ===================== MAIN ================================
SRC = minishell.c globale.c $(GARBAGE_COLLECTOR) $(HELPER_FUNCTIONS) $(PARSING) $(BUILT_IN)

OBJ = $(SRC:.c=.o)

# ===================== RULES ===============================
all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
