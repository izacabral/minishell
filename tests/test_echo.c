/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:49:57 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/05/15 21:08:19 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	check_n(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1] == 'n')
	{
		i = 1;
		while (str[i] == 'n' && str[i])
			i++;
		if (str[i] != 'n' && str[i])
			return (0);
		else
			return (1);
	}
}

int	ft_echo(char **arg)
{
	int	control;
	int	i;

	i = 1;
	control = 0;
	if (arg[i] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	while ((ft_strncmp(arg[i], "-n", 2) == 0) && (check_n(arg[i]) == 1))
	{
			control = 1;
			i++;
	}
	while (arg[i])
	{
		ft_putstr_fd (arg[i], 1);
		if (arg[i] && arg[i + 1])
			ft_putstr_fd(" ", 1);
			i++;
	}
	if (control == 0)
		ft_putstr_fd("\n", 1);
}
