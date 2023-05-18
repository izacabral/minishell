/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:50 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/14 15:55:14 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_stradd_front(t_string **lst, t_string *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		new->last = (*lst)->last;
		new->next = *lst;
		*lst = new;
	}
}
