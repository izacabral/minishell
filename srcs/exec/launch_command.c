#include "minishell.h"

/*
 * Fn		: launch_command(char **args)
 * Scope	: cria um processo que chama execve()
 * Input	: char ** - argumentos para execve()
 * Output	: int - 0 (sucesso)
 * Errors	: -1 - erro do execve()
 * Uses		: call_execve (call_execve.c)
 */
int	launch_command(char **args)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		if ((execve(*args, args, NULL)) < 0)
			exit(-1);
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}
