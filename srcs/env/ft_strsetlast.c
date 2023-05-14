/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:56 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/14 15:57:21 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_strsetlast(t_string *lst, t_string *laststr)
{
	while (lst)
	{
		lst->last = laststr;
		lst = lst->next;
	}
}
