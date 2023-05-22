#include "libft.h"
#include "minishell.h"

static int	get_exitarg(char *arg, int last);

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
	int	exit_value;

	if (builtin == ECHO)
		return (/*call echo*/);
	if (builtin == CD)
		return (/*call cd*/);
	if (builtin == PWD)
		return (/*call pwd*/);
	if (builtin == EXPORT)
		return (/*call export*/);
	if (builtin == UNSET)
		return (/*call unset*/);
	if (builtin == ENV)
		return (/*call env*/);
	if (builtin == EXIT)
	{
		exit_value = 0; // substituir pro valor de saída do último comando
		if (args[1])
			exit_value = get_exitarg(args[1], exit_value);
		// liberar mémoria alocada
		return (/*call exit*/);
	}
	return (0);
}

static int	get_exitarg(char *arg, int last)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (last);
		i++;
	}
	return (ft_atoi(arg));
}
