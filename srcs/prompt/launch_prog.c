/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/11 15:58:34 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_sentence_teste(t_sentence **lst_sentence)
{
	t_sentence *tmp;

	tmp = *lst_sentence;
	if (!tmp)
		return ;
	while (tmp)
	{
		char **args = tmp->args;
		int i;
		i = 0;
		while (args[i])
		{
			ft_printf("print sentence args[%d]: %s\n", i, args[i]);
			i++;
		}
		args = NULL;
		tmp = tmp->next;
	}
}


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

		print_sentence_teste(&data->lst_sentence);

		ft_printf("Number of sentences: %d\n", data->sentence_count);
		ft_printf("Number of pipes: %d\n", data->pipe_count);
		ft_printf("Number of redirects: %d\n", data->redirect_count);
		open_pipe_reds(data);
		clean_reds_sentences(data);
		print_sentence_teste(&data->lst_sentence);
	}
	clear_token(&data->lst_token);
	if (data->lst_sentence)
	{
		clear_sentence(&data->lst_sentence);
		fill_shell(data);
	}
}
