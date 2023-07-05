/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:24:22 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:02 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
