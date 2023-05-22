#include "minishell.h"

static t_builtin	isbuiltin(char *comm);

int	exec_command(char *comm, char **args, t_shell *data)
{
	t_builtin	builtin;

	builtin = isbuiltin(comm);
	if (builtin)
	{
	//	launch call builtin
	//	return
	}
	// call execve
	// return
	return (0);
}

static t_builtin	isbuiltin(char *comm)
{
	if (!ft_strncmp(comm, "echo", 5))
		return (ECHO);
	if (!ft_strncmp(comm, "cd", 3))
		return (CD);
	if (!ft_strncmp(comm, "pwd", 4))
		return (PWD);
	if (!ft_strncmp(comm, "export", 7))
		return (EXPORT);
	if (!ft_strncmp(comm, "unset", 6))
		return (UNSET);
	if (!ft_strncmp(comm, "env", 4))
		return (ENV);
	if (!ft_strncmp(comm, "exit", 5))
		return (EXIT);
	return (ENOBLTN);
}
