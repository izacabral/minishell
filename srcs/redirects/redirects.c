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

void	redirect(t_sentence *cmd, t_sentence *file, char *redirect)
{
	if (ft_strequal(redirect, "<") == 0)
		red1(cmd, file);
	if (ft_strequal(redirect, "<<") == 0)
		red2(cmd, file);
	if (ft_strequal(redirect, ">") == 0)
		red3(cmd, file);
	if (ft_strequal(redirect, ">>") == 0)
		red4(cmd, file);
}

void	red3(t_sentence *cmd, t_sentence *file)
{
	int	temp_fd;

	temp_fd = open(file->args[0], O_WONLY | O_TRUNC | O_CREATE, 0777);
	if (temp_fd == -1)
	{
		write(2, "ERROR", 5);
		return ;
	}
	file->fd_i = temp_fd;
	dup2(file->fd_i, cmd->fd_o);
}

void	red4(t_sentence *cmd, t_sentence *file)
{
	int	temp_fd;

	temp_fd = open(file->args[0], O_WONLY | O_APPEND | O_CREATE, 0777);
	if (temp_fd == -1)
	{
		write(2, "ERROR", 5);
		return ;
	}
	file->fd_i = temp_fd;
	dup2(file->fd_i, cmd->fd_o);
}

void	red1(t_sentence *cmd, t_sentence *file)
{
	int	temp_fd;

	temp_fd = open(file->args[0], O_RONLY, 0777);
	if (temp_fd == -1)
	{
		write(2, "ERROR", 5);
		return ;
	}
	file->fd_o = temp_fd;
	dup2(cmd->fd_i, file->fd_o);
}
