#include "../built_in.h"

void	cd_home(char *oldpwd)
{
	char	*home;

	home = get_value_from_env("HOME");
	if (chdir(home) < 0)
		perror("minishell :");
	else
	{
		change_pwd_var();
		change_oldpwd_var(oldpwd);
	}
}

void	cd_back(char *oldpwd)
{
	char	*prev_wd;

	prev_wd = get_value_from_env("OLDPWD");
		
	if (prev_wd == NULL || chdir(prev_wd) < 0)
		perror("minishell: ");
	else
	{
		if(prev_wd)
			print_msg_to_fd(prev_wd, "\n", NULL, 1);
		change_pwd_var();
		change_oldpwd_var(oldpwd);
	}
}
