/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:25:23 by daolivei          #+#    #+#             */
/*   Updated: 2023/04/28 12:58:34 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	ft_strclear(t_string **lst, void (*del)(void *))
{
	t_string	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_strdelone(tmp, del);
	}
	*lst = NULL;
}
