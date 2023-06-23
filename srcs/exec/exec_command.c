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
	t_env		*path;

	builtin = isbuiltin(comm);
	if (builtin)
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
