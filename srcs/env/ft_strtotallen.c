/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtotallen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:30:07 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/14 16:30:09 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
