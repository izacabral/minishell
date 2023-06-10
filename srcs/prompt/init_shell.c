/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/30 16:52:17 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *data, char *envp[])
{
	data->line = NULL;
	data->lst_env = get_env(envp);
	data->lst_token = NULL;
	data->sentence_count = 0;
	data->pipe_count = 0;
	data->redirect_count = 0;
	data->pipes = NULL;
	data->reds = NULL;
}
