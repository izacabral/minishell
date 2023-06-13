/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:03:04 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/12 20:03:08 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void error_pipe(void)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	g_global = errno;
}

int	*open_pipe(t_sentence *actual, t_sentence *next)
{
	int	*pipe_fd;

	pipe_fd = malloc (sizeof(int) * 2);
	if (!pipe_fd)
		return (NULL);
	if (pipe(pipe_fd) == -1)
	{
		free(pipe_fd);
		error_pipe();
		return (NULL);
	}
	if (actual->previous != NULL && actual->fd_i == 0)
		actual->fd_i = pipe_fd[0];
	if (actual->fd_o == 1 && next != NULL)
		actual->fd_o = pipe_fd[1];
	return (pipe_fd);
}
