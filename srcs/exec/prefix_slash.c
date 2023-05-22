/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:41:06 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/19 14:41:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: prefix_slash(char **str)
 * Scope	: modifica *str, prefixando '/'
 * Input	: char ** - endereço de uma string
 * Output	: char * - a string modificada
 * Errors	: NULL - erro na alocação, ou *str é NULL
 * Uses		: test_command (call_execve.c)
 */
char	*prefix_slash(char **str)
{
	char			*output;
	const size_t	len = ft_strlen(*str);

	if (!*str)
		return (NULL);
	output = malloc((len + 2) * sizeof(*output));
	if (!output)
		return (NULL);
	*output = '/';
	ft_memcpy(&output[1], *str, len + 1);
	free(*str);
	*str = NULL;
	*str = output;
	return (output);
}
