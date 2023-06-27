/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:25:38 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/23 15:25:44 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_global(char *var, int size)
{
	char	*value;
	char	*rest;

	value = ft_itoa(g_global);
	if (size == 0)
		return (value);
	else
	{
		rest = ft_substr(var, 1, size);
		value = ft_strjoin_free(value, rest);
		free(rest);
		return (value);
	}
}
