/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcalvell <gcalvell@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:30:43 by gcalvell          #+#    #+#             */
/*   Updated: 2023/06/09 00:30:43 by gcalvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void error_redir(char *filename)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	g_global = 1;
}

int	out(t_sentence *cmd, char *file)
{
	int	temp_fd;

	temp_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC , 0666);
	if (temp_fd == -1)
	{
		error_redir(file);
		return (-1);
	}
	cmd->fd_o = temp_fd;
	return (temp_fd);
}

int	append(t_sentence *cmd, char *file)
{
	int	temp_fd;

	temp_fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (temp_fd == -1)
	{
		error_redir(file);
		return (-1);
	}
	cmd->fd_o = temp_fd;
	return (temp_fd);
}

int	in(t_sentence *cmd, char *file)
{
	int	temp_fd;

	temp_fd = open(file, O_RDONLY);
	if (temp_fd == -1)
	{
		error_redir(file);
		return (-1);
	}
	cmd->fd_i = temp_fd;
	return (temp_fd);
}

int	open_reds(int token, t_sentence *cmd, char *file_name)
{
	if (token == IN)
		return (in(cmd, file_name));
	else if (token == OUT)
		return (out(cmd, file_name));
	else if (token == APPEND)
		return (append(cmd, file_name));
	else
		return (-1);
}