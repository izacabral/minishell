/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:41:23 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/19 14:41:24 by daolivei         ###   ########.fr       */
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
