/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe_reds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:28:57 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/06 16:35:33 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*open_pipe(t_sentence *previous, t_sentence *after)
{
	char **argsp = previous->args;
	int i;
	i = 0;
	while (argsp[i])
	{
		ft_printf("argsp[%d]: %s\n", i, argsp[i]);
		i++;
	}
	char **argsa = after->args;
	i = 0;
	while (argsa[i])
	{
		ft_printf("argsa[%d]: %s\n", i, argsa[i]);
		i++;
	}
	return (0);
}
int open_reds(int token, t_sentence *cmd, char *file_name)
{
	char **argscmd = cmd->args;
	int i;
	i = 0;
	while (argscmd[i])
	{
		ft_printf("argscmd[%d]: %s\n", i, argscmd[i]);
		i++;
	}
	ft_printf("token: %d\n", token);
	ft_printf("filename: %s\n", file_name);
	return (0);
}

int	open_pipe_reds(t_shell *data)
{
	t_token		*tmp_token;
	t_sentence	*tmp_sentence;

	tmp_token = data->lst_token;
	tmp_sentence = data->lst_sentence;
	if (!tmp_token || !tmp_sentence)
		return (-1);
	while (tmp_token)
	{
		if (tmp_token->tkn == PIPE)
		{
			if (tmp_sentence->next)
			{
				open_pipe(tmp_sentence, tmp_sentence->next);
				tmp_sentence = tmp_sentence->next;
			}
			else
				open_pipe(tmp_sentence, NULL);
		}
		if (tmp_token->tkn != PIPE && tmp_token->tkn != WORD)
		{
			if(tmp_sentence->previous == NULL)
				open_reds(tmp_token->tkn, tmp_sentence, tmp_sentence->args[0]);
			else
				open_reds(tmp_token->tkn, tmp_sentence->previous, tmp_sentence->args[0]);
			tmp_sentence = tmp_sentence->next;
		}
		tmp_token = tmp_token->next;
	}
	return (0);
}
