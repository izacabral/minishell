#include "libft.h"
#include "minishell.h"

static int	args_size(char **args);

/*
 * Fn		: call_builtin(char **args, t_shell *data, t_builtin builtin)
 * Scope	: prepara argumentos e chama o builtin
 * Input	: char ** - argumentos a serem passados
 *			: t_shell * - ponteiro para estrutura global
 *			: t_builtin - o builtin a ser chamado
 * Output	: int - mesmo retornos do builtin
 * Errors	: dependente dos comandos
 * Uses		: [WIP] a ser integrado.
 */
int	call_builtin(char **args, t_shell *data, t_builtin builtin)
{
	const int	size = args_size(args);

	default_signals();
	if (builtin == ECHO)
		return (echo(args));
	if (builtin == CD)
		return (cd(data, args[1]));
	if (builtin == PWD)
		return (pwd());
	if (builtin == EXPORT)
		return (export(size, args, data->lst_env));
	if (builtin == UNSET)
		return (unset(size, args, &data->lst_env));
	if (builtin == ENV)
	{
		env(data->lst_env);
		return (0);
	}
	if (builtin == EXIT)
		ft_exit(args, data, size);
	return (0);
}

static int	args_size(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}


