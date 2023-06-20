/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:47:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/19 23:18:49 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **args, t_shell *data, int size)
{
	char		*arg;

	arg = NULL;
	if (size == 1)
	{
		g_global = 0;
		free_shell(data);
		exit(0);
	}
	else if (args[1] != NULL)
	{
		arg = ft_itoa(ft_atoi(args[1]));
		if (ft_strncmp(arg, args[1], ft_strlen(args[1]) + 1) != 0)
		{
			free(arg);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			free_shell(data);
			exit(g_global);
		}
		else
		{
			g_global = ft_atoi(args[0]);
			free_shell(data);
			exit(g_global);
		}
	}
	else if (size > 2)
	{
		ft_putendl_fd("exit", 2);
		ft_putendl_fd("minishell: exit: too many argument", 2);
	}
}
