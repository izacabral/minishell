/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_hdoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:22:57 by izsoares          #+#    #+#             */
/*   Updated: 2023/07/03 13:23:22 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_cmd(t_sentence *cmd)
{
	cmd->args = NULL;
	cmd->fd_i = 0;
	cmd->fd_o = 1;
	cmd->previous = NULL;
	cmd->next = NULL;
}

void	has_hdoc(t_token *lst)
{
	t_token		*tmp;
	t_sentence	cmd;
	char		*file;
	t_env		*env;

	tmp = lst;
	env = NULL;
	while (tmp->previous)
	{
		tmp = tmp->previous;
		if (tmp->tkn == HDOC)
			break ;
	}
	if (tmp && tmp->tkn == HDOC)
	{
		file = ft_strdup(tmp->next->word);
		init_cmd(&cmd);
		heredoc(&cmd, file, env);
		free (file);
	}
}
