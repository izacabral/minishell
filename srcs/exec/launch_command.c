/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:41:23 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/29 12:41:48 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: launch_command(char **args)
 * Scope	: cria um processo que chama execve()
 * Input	: char ** - argumentos para execve()
 * Output	: int - 0 (sucesso)
 * Errors	: -1 - erro do execve()
 * Uses		: call_execve (call_execve.c)
 */
int	launch_command(char **args, t_shell *data)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		if ((execve(*args, args, data->env_dup)) < 0)
			exit(-1);
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}
