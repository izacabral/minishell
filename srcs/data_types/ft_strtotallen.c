/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtotallen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:30:07 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:28 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strtotallen(t_string *lst)
{
	size_t	total_len;

	total_len = 0;
	while (lst)
	{
		total_len += lst->length;
		lst = lst->next;
	}
	return (total_len);
}
