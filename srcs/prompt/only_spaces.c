/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:06:02 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/13 12:07:03 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
		return (0);
		i++;
	}
	return (1);
}