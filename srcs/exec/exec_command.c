/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:09:25 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/20 00:09:27 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	t_env		*path;

	builtin = isbuiltin(comm);
	if (builtin && data->sentence_count > 1)
	{
		call_builtin(args, data, builtin);
		free_shell(data);
		clear_env(&data->lst_env);
		exit(0);
	}
	else
	{
		path = compare_key(data->lst_env, "PATH");
		return (call_execve(args, path->value));
	}
}
