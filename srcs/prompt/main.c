/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/19 09:46:51 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global = 0;

//init **lst_env 
//data->lst_sentence = NULL;
void	init_shell(t_shell *data)
{
	data->line = NULL;
	data->lst_token = NULL;
	data->sentence_count = 0;
	data->pipe_count = 0;
	data->redirect_count = 0;
	data->pipes = NULL;
	data->reds = NULL;
}

int	main(void)
{
	t_shell	data;

	init_shell(&data);
	setup_signals();
	while (1)
	{
		data.line = rl_gets(data.line);
		if (!data.line)
			break ;
		if (!ft_strncmp(data.line, "exit", 5))
		{
			free(data.line);
			break ;
		}
		launch_prog(&data);
		if (*data.line)
			add_history(data.line);
	}
	return (0);
}
