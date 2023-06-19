/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:01:33 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/14 22:50:22 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isquoted(char *str)
{
	while (*str)
	{
		if (isquotes(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	hdoc_routine(char *file, int expand, int fd, t_env *env)
{
	char	*line_read;
	int		size;

	size = ft_strlen(file) + 1;
	line_read = NULL;
	while (1)
	{
		line_read = readline("> ");
		if (!line_read)
			return (-1);
		if (ft_strncmp(line_read, file, size) == 0)
		{
			free(line_read);
			break ;
		}
		if (expand)
			expand_hdoc_var(&line_read, env);
		ft_putendl_fd(line_read, fd);
		free(line_read);
	}
	return (0);
}

int	heredoc(t_sentence *cmd, char *file, t_env *env)
{
	int		expand;
	int		pipe_fd[2];

	expand = !isquoted(file);
	if (!expand)
		file = ft_strdup((remove_hdoc_quotes(file)));
	if (pipe(pipe_fd) == -1)
	{
		error_redir(file);
		return (-1);
	}
	if ((hdoc_routine(file, expand, pipe_fd[1], env)) == -1)
		return (-1);
	cmd->fd_i = pipe_fd[0];
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}
