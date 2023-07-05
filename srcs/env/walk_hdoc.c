/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_hdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:56:57 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/04 17:44:12 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	walk_hdoc(char *str, t_string **output, int index)
{
	int	i;

	i = 2;
	if (!str[i + index])
	{
		stash_string(output, str, i + index);
		return (i);
	}
	while (ft_isspace(str[i + index]))
		i++;
	while (str[i + index] && !ft_isspace(str[i + index]))
		i++;
	if (!output)
		stash_string(output, str, i + index);
	else
		stash_string(output, &str[index], i);
	return (i);
}
