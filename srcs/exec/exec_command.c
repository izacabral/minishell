#include "exec.h"
#include "minishell.h"

static t_builtin	isbuiltin(char *comm);

/*
 * Fn		: exec_command(char *comm, char **args, t_shell *data)
 * Scope	: interface para executar comandos builtins ou por execve
 * Input	: char * - string com o nome do comando
 *			: char ** - argumentos a serem passados
 *			: t_shell * - ponteiro para estrutura global
 * Output	: int - mesmo retornos dos comandos
 * Errors	: dependente dos comandos
 * Uses		: [WIP] a ser integrado.
 */
int	exec_command(char *comm, char **args, t_shell *data)
{
	t_builtin	builtin;

	builtin = isbuiltin(comm);
	if (builtin)
		return (call_builtin(args, data, builtin));
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
