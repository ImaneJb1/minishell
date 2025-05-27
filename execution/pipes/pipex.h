#include "../../minishell.h"
#include "../../parsing/parsing.h"
#include "../built_ins/built_in.h"
#include <sys/types.h>
#include <sys/wait.h>

void	execute_commands(t_exec *cmd, int *fd);
int		pipes(void);