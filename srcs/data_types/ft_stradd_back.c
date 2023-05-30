/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:22 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/14 15:54:35 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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