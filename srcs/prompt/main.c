/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/13 12:07:50 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global = 0;

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	data;

	if (argc != 1)
	{
		ft_putendl_fd("\e[31m---Too many arguments---\e[0m", 2);
		return (0);
	}
	(void) argv;
	init_shell(&data);
	data.lst_env = get_env(envp);
	while (1)
	{
		setup_signals();
		data.line = readline_gets(data.line);
		if (!data.line)
			break ;
		if (*data.line && !only_spaces(data.line))
			add_history(data.line);
		launch_prog(&data);
	}
	free_shell(&data);
	clear_env(&data.lst_env);
	rl_clear_history();
	return (0);
}
