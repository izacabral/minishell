/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_varname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:29:37 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/06 13:29:39 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_varname(char *key)
{
	if (!ft_isalpha(*key) || *key != '_')
		return (1);
	key++;
	while(*key)
	{
		if (!ft_isalnum(*key) || *key !='_')
			return (1);
		key++;
	}
	return (0);
}
