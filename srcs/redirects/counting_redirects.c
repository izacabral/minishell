/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:04:45 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/11 17:15:58 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	counting_redirects(t_token **lst_token)
{
	t_token	*tmp;
	int		count;

	tmp = *lst_token;
	count = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->tkn > PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
