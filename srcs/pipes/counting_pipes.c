/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couting_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:57:50 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/05 16:10:06 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int counting_pipes(t_token *lst_token)
{
	int count;

	count = 0;
	if (!lst_token)
		return (0);
	while (lst_token)
	{
		if (lst_token->tkn == PIPE)
			count++;
		lst_token = lst_token->next;
	}
	return (count);
}

