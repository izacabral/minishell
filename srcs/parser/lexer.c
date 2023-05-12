/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:26:25 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/09 18:06:33 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int lexer(t_token *lst)
{
	t_token *tmp;
	printf("entrei na lexer\n");

	tmp = lst;
	if (!tmp)
		return (-1);
	if (tmp->tkn == PIPE)
	{
		return (-2);
	}
	while (tmp->next)
	{
		//printf("%s\n", tmp->word);
		if ((tmp->tkn == WORD || tmp->tkn == PIPE) && tmp->next)
			tmp = tmp->next;
		else if (tmp->tkn == IN || tmp->tkn == OUT || tmp->tkn == HDOC || tmp->tkn == APPEND)
		{
			if (!tmp->next)
			{
				//clear_token(&lst);
				return (-2);
				// syntax error newline
			}
			if (tmp->next->tkn == PIPE)
			{
				//clear_token(&lst);
				return (-2);
				// syntax error pipe
			}
			tmp = tmp->next;
		}
	}
	return (0);
}
