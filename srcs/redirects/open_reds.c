/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcalvell <gcalvell@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:30:43 by gcalvell          #+#    #+#             */
/*   Updated: 2023/06/13 09:54:45 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	error_redir(char *filename)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	g_global = errno;
}

int	out(t_sentence *cmd, char *file)
{
	int	temp_fd;

	if (cmd->fd_i == -1 || cmd->fd_o == -1)
	{
		temp_fd = -1;
		return (temp_fd);
	}
	else
		temp_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (temp_fd == -1)
		error_redir(file);
	cmd->fd_o = temp_fd;
	return (temp_fd);
}

int	append(t_sentence *cmd, char *file)
{
	int	temp_fd;

	if (cmd->fd_i == -1 || cmd->fd_o == -1)
	{
		temp_fd = -1;
		return (temp_fd);
	}
	else
		temp_fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (temp_fd == -1)
		error_redir(file);
	cmd->fd_o = temp_fd;
	return (temp_fd);
}

int	in(t_sentence *cmd, char *file)
{
	int	temp_fd;

	if (cmd->fd_i == -1 || cmd->fd_o == -1)
	{
		temp_fd = -1;
		return (temp_fd);
	}
	else
		temp_fd = open(file, O_RDONLY);
	if (temp_fd == -1)
		error_redir(file);
	cmd->fd_i = temp_fd;
	return (temp_fd);
}

/*
 * Fn		: open_reds(int token, t_sentence *cmd, char *file_name)
 * Scope	: open the files and updade the fds in sentence
 * Input	: token (type of redir), the sentence that has the cmd and
 * 				the file name
 * Output	: the created fd or 1 in error
 * Errors	: -1 if the fd wasn't created
 * Uses		: open_pipe_reds()
 */
int	open_reds(int token, t_sentence *cmd, char *file_name, t_env *env)
{
	if (token == IN)
		return (in(cmd, file_name));
	else if (token == OUT)
		return (out(cmd, file_name));
	else if (token == APPEND)
		return (append(cmd, file_name));
	else if (token == HDOC)
		return (heredoc(cmd, file_name, env));
	else
		return (-1);
}
