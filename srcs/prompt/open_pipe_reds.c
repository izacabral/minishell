/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe_reds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:28:57 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/06 13:53:29 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*open_pipe(t_sentece *previous, t_sentece *after)
{
	ft_printf()
}
int open_reds(int token, t_sentece *cmd, char *file_name)

int	open_pipe_reds(t_shell *data)
{
	t_token		*tmp_token;
	t_sentence	*tmp_sentence;

	tmp_token = &data->lst_token;
	tmp_sentence = &data->lst_sentence;
	if (!tmp_token || !tmp_sentence)
		return (-1);
	while (tmp_token)
	{
		if (tmp_token->tkn == PIPE)
		{
			if (tmp_sentence->next)
			{
				call_pipe(tmp_sentence, tmp_sentence->next);
				tmp_sentence = tmp_sentence->next;
			}
			else
				call_pipe(tmp_sentence, NULL);
		}
		if (tmp_token->tkn != PIPE && tmp_token->tkn != WORD)
		{
			call_
		}
	}
	return (0);
}
