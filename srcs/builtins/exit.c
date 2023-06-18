/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:47:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/05/20 11:10:05 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **args, t_shell *data)
{
	char *arg;

	arg = NULL;
	if (args == NULL)
	{
		g_global = 0;
		free_shell(data);
		exit(0);
	}
	if (args[1] != NULL)
	{
		arg = ft_itoa(ft_atoi(args[1]));
		if (ft_strncmp(arg, args[1], ft_strlen(args[1]) + 1) != 0)
		{
			free(arg);
			ft_putendl_fd("minishell: exit: ", 2);
			ft_putendl_fd(args[1], 2);
			ft_putendl_fd(": numeric argument required\n", 2);
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
	return (0);
}
