/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/11 17:14:03 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (data->sentence_count == 1
			&& !ft_strncmp(data->lst_sentence->args[0], "exit", 5))
			call_builtin(data->lst_sentence->args, data, EXIT);
		else
			executor(data);
	}
	free_shell(data);
}
