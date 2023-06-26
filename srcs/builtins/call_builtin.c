/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:08:55 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/22 21:05:03 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	//default_signals();
	if (builtin == ECHO)
		return (echo(args, 1));
	if (builtin == CD)
		return (cd(size, args, data));
	if (builtin == PWD)
		return (pwd(1));
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
