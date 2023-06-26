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
	//default_signals();
	//setup_signals();
	setup_hdoc_sig();
	g_global = 0;
	while (1)
	{
		line_read = readline("> ");
		if (!line_read || g_global != 0)
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
	char	*cpy_file;

	cpy_file = ft_strdup(file);
	expand = !isquoted(cpy_file);
	if (!expand)
		cpy_file = ft_strdup((remove_hdoc_quotes(cpy_file)));
	if (pipe(pipe_fd) == -1)
	{
		error_redir(cpy_file);
		return (-1);
	}
	if ((hdoc_routine(cpy_file, expand, pipe_fd[1], env)) == -1)
		pipe_fd[0] = -1;
	cmd->fd_i = pipe_fd[0];
	close (pipe_fd[1]);
	free(cpy_file);
	setup_signals();
	return (pipe_fd[0]);
}
