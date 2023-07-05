/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:56 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:22 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strsetlast(t_string *lst, t_string *laststr)
{
	while (lst)
	{
		lst->last = laststr;
		lst = lst->next;
	}
}
