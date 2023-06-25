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

	if (argc != 1 && ft_strncmp(argv[1], "minishell", 10))
	{
		ft_putendl_fd("\e[31m---Invalid parameters! Try:\e[0m", 2);
		ft_putendl_fd("\e[32m./minishell\e[0m", 2);
		return (0);
	}
	init_shell(&data);
	data.lst_env = get_env(envp);
	setup_signals();
	while (1)
	{
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
