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

//===============================
// ATENÇÃO
// VERIFICAR PERMISSÕES NO MAC
//===============================

int	open_reds(int token, t_sentence *cmd, char *file_name)
{
	if (token == IN)
		return (in(cmd, file_name));
	else if (token == OUT)
		return (out(cmd, file_name));
	else if (token == APPEND)
		return (append(cmd, file));
	else
		return (-1);
}

void	out(t_sentence *cmd, char *file)
{
	int	temp_fd;

	temp_fd = open(file, O_WONLY | O_TRUNC | O_CREATE, 0777);
	if (temp_fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	dup2(temp_fd, cmd->fd_o);
	return (temp_fd);
}

void	append(t_sentence *cmd, t_sentence *file)
{
	int	temp_fd;

	temp_fd = open(file, O_WONLY | O_APPEND | O_CREATE, 0777);
	if (temp_fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	dup2(temp_fd, cmd->fd_o);
	return (temp_fd);
}

void	in(t_sentence *cmd, char *file)
{
	int	temp_fd;

	temp_fd = open(file, O_RONLY, 0777);
	if (temp_fd == -1)
	{
		strerror(errno);
		return (-1);
	}
	dup2(cmd->fd_i, temp_fd);
	return (temp_fd);
}
