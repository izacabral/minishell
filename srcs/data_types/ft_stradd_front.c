/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:50 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:10 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
