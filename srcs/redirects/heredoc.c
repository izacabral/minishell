/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:01:33 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/03 15:59:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(t_sentence *cmd, char *file)
{
	char	*line_read;
	int		pipe_fd[2];

	line_read = NULL;
	if (pipe(pipe_fd) == -1)
	{
		error_redir(file);
		return (-1);
	}
	close(pipe_fd[1]);
	while (1)
	{
		line_read = readline(">");
		if (!line_read)
			return (-1);
		if (ft_strncmp(line_read, file, ft_strlen(file)) == 0)
			break ;
		ft_putendl_fd(line_read, pipe_fd[0]);
		free(line_read);
	}
	free(line_read);
	cmd->fd_i = pipe_fd[0];
	return (pipe_fd[0]);
}

