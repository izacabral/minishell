/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:18:53 by izsoares          #+#    #+#             */
/*   Updated: 2023/07/03 17:27:55 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_buf(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
	{
		length++;
		if (length > BUFLIM)
			return (1);
	}
	return (0);
}

void	check_buf(char **str)
{
	if (ft_strlen_buf(*str))
	{
		free(*str);
		*str = NULL;
	}
}
