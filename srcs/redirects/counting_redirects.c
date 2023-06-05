/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:04:45 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/05 16:06:33 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int counting_redirects(t_token *lst_token)
{
	int count;

	count = 0;
	if (!lst_token)
		return (0);
	while (lst_token)
	{
		if (lst_token->tkn != PIPE && lst_token->tkn != WORD)
			count++;
		lst_token = lst_token->next;
	}
	return (count);
}
