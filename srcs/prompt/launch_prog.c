/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 16:31:37 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

static void	trim_line(t_shell *data);

/*
 * Fn		: launch_prog(t_shell *data)
 * Scope	: Run the REPL loop
 * Input	: t_shell * - pointer to the global struct
 * Output	: void
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
void	launch_prog(t_shell *data)
{
	if (data->line == NULL)
		return ;
	data->line = expand_sentence(&data->line, data->lst_env, 0);
	trim_line(data);
	if (scan_line(&data->lst_token, data->line) == 0
		&& lexer(data->lst_token) == 0)
	{
		create_sentences(data->lst_env, &data->lst_token, &data->lst_sentence);
		fill_shell (data);
		if (data->pipe_count > 0 || data->redirect_count > 0)
		{
			open_pipe_reds(data);
			clean_reds_sentences(data->lst_sentence);
		}
		executor(data);
	}
}

static void	trim_line(t_shell *data)
{
	char		*tmp;
	t_quotes	q;

	tmp = data->line;
	if (!tmp)
		return ;
	while (*tmp)
	{
		q = which_quotes(*tmp);
		if (q && which_quotes(*(tmp + 1)) == q)
		{
			*tmp = ' ';
			*(tmp + 1) = ' ';
		}
		tmp++;
	}
	tmp = data->line;
	data->line = ft_strtrim(tmp, " ");
	free(tmp);
}
