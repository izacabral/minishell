#include "minishell.h"

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

int	g_global = 0;

int    main()
{
    t_sentence *cmd;

	cmd = malloc (sizeof(t_sentence));
	cmd->args = NULL;
	cmd->fd_i = 0;
	cmd->fd_o = 1;
	cmd->reds_inside = 0;
	cmd->previous = NULL;
	cmd->next = NULL;


	if (heredoc(cmd, "EOF") == -1)
	{
		ft_printf("error hdoc\n");
		return (-1);
	}
	ft_printf("fd_i: %d\n", cmd->fd_i);
	
	free(cmd);
    return (0);
}
