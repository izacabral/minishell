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


int	heredoc(t_sentence *cmd, char *file, t_env *env)
{
	char	*line_read;
	int		expand;
	int		pipe_fd[2];

	expand = isquoted(file);
	if (expand)
		file = remove_hdoc_quotes(file);
	line_read = NULL;
	if (pipe(pipe_fd) == -1)
	{
		error_redir(file);
		return (-1);
	}
	while (1)
	{
		line_read = readline(">");
		if (!line_read)
		{
			free(line_read);
			return (-1);
		}
		if (ft_strncmp(line_read, file, ft_strlen(file) + 1) == 0)
		{
			free(line_read);
			break ;
		}
		if (!expand)
			expand_hdoc_var(&line_read, env);
		ft_putendl_fd(line_read, pipe_fd[1]);
		free(line_read);
	}
	cmd->fd_i = pipe_fd[0];
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}
