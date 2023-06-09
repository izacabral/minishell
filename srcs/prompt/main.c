/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/02 13:31:37 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global = 0;

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	data;

	(void)(argv);
	(void)(argc);
	init_shell(&data, envp);
	setup_signals();
	while (1)
	{
		data.line = readline_gets(data.line);
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
	clear_env(&data.lst_env);
	return (0);
}
