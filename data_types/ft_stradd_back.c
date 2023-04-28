/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:22 by daolivei          #+#    #+#             */
/*   Updated: 2023/04/28 12:57:56 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	ft_stradd_back(t_string **lst, t_string *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		(*lst)->last->next = new;
		ft_strsetlast(*lst, new);
	}
}
