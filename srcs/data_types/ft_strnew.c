/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:31:08 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:19 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_string	*ft_strnew(char *str, size_t length)
{
	t_string	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = str;
	new->length = length;
	new->last = new;
	new->next = NULL;
	return (new);
}
