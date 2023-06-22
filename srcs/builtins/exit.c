/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:47:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/21 14:37:35 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	calc_return(long int n)
{
	int	ret;

	if (n > 0)
		ret = n % 256;
	if (n < 0)
	{
		ret = n % 256;
		if (ret < 0)
			ret += 256;
	}
	else
		ret = 0;
	return (ret);
}

static void	exit_case2(char **args, t_shell *data)
{
	char	*arg;

	arg = ft_ltoa(ft_atol(args[1]));
	if (ft_strncmp(arg, args[1], ft_strlen(args[1]) + 1) == 0)
	{
		free(arg);
		if (data->sentence_count == 1)
			ft_putendl_fd("exit", 2);
		free_shell(data);
		clear_env(&data->lst_env);
		g_global = calc_return (ft_atol(args[1]));
		exit(g_global);
	}
	else
	{
		free(arg);
		if (data->sentence_count == 1)
			ft_putendl_fd("exit", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		free_shell(data);
		clear_env(&data->lst_env);
		g_global = 255;
		exit(g_global);
	}
}

void	ft_exit(char **args, t_shell *data, int size)
{
	if (data->lst_sentence->fd_i == -1)
		return ;
	if (size == 1)
	{
		if (data->sentence_count == 1)
			ft_putendl_fd("exit", 2);
		g_global = 0;
		free_shell(data);
		clear_env(&data->lst_env);
		exit(0);
	}
	if (size == 2)
		exit_case2(args, data);
	if (size > 2)
	{
		if (data->sentence_count == 1)
			ft_putendl_fd("exit", 2);
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		g_global = 1;
	}
}
