/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_varname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:29:37 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/06 15:56:29 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_varname(char *key)
{
	int	len;

	len = 0;
	if (!(ft_isalpha(key[len]) || key[len] != '_'))
		return (0);
	len++;
	while(key[len])
	{
		if (!(ft_isalnum(key[len]) || key[len] !='_'))
			return (0);
		len++;
	}
	return (0);
}
