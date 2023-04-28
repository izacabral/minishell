/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:30:46 by daolivei          #+#    #+#             */
/*   Updated: 2023/04/28 15:59:39 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	ft_strsize(t_string *lst)
{
	int	nodes;

	nodes = 0;
	while (lst)
	{
		nodes++;
		lst = lst->next;
	}
	return (nodes);
}
