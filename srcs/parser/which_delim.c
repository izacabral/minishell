/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:15:57 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/03 11:15:58 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	which_delim(char *delim)
{
	char	c;

	c = *delim;
	if (!isdelim(c))
		return (ERROR);
	if (c == '|')
		return (PIPE);
	if (c == '>')
	{
		if (*(delim + 1) == c)
			return (APPEND);
		return (OUT);
	}
	if (c == '<')
	{
		if (*(delim + 1) == c)
			return (HDOC);
		return (IN);
	}
	return (ERROR);
}
