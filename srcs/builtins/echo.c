/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:49:57 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/07/04 18:22:33 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_n(char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i] && str[i] != 'n')
		return (0);
	return (1);
}

int	echo(char **arg, int fd)
{
	int	control;
	int	i;

	i = 1;
	control = 0;
	if (arg[i] && (ft_strncmp(arg[i], "-n", 2) == 0))
		control = check_n(arg[i]);
	while (control && arg[++i])
	{
		if (ft_strncmp(arg[i], "-n", 2) || !check_n(arg[i]))
			break ;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		if (arg[i] && arg[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (arg[i - 1] == NULL || control == 0)
		ft_putstr_fd("\n", fd);
	return (0);
}
