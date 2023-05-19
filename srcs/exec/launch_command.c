#include "minishell.h"

int	launch_command(char **args)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		if ((execve(*args, args, NULL)) < 0)
		{
			ft_putstr_fd("Failed to call execve\n", 1);
			exit(-1);
		}
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}
