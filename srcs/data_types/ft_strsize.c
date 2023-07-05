/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:30:46 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:24:25 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
