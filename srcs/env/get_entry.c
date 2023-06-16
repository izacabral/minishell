/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:35:24 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/12 22:28:32 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_entry(char **key, char **value, char *var, int len)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	*key = ft_substr(var, 0, i);
	if (var[i])
		i++;
	*value = ft_substr(var, i, len - i);
	if (*value && !**value)
	{
		free(*value);
		*value = NULL;
	}
}
