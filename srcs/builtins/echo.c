/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:49:57 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/19 23:15:56 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_n(char *str)
{
	int	i;

	i = 2;
	while (str[i] == 'n' && str[i])
		i++;
	if (str[i] != 'n' && str[i])
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
	if (control)
		i++;
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
