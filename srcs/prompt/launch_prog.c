/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/05 17:10:10 by izsoares         ###   ########.fr       */
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
		//fill_shell (data);
		while (data->lst_sentence)
		{
			char **args = data->lst_sentence->args;
			int i;
			i = 0;
			while (args[i])
			{
				ft_printf("args[%d]: %s\n", i, args[i]);
				i++;
			}
			args = NULL;
			data->lst_sentence = data->lst_sentence->next;

		}
	}
	else
	{
		clear_token(&data->lst_token);
		if (data->lst_sentence)
			clear_sentence(&data->lst_sentence);

	}
	//ft_printf("Number of pipes: %d", data->pipe_count);
	//ft_printf("Number of redirects: %d", data->redirect_count);
}
