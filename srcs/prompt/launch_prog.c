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

//apenas para uso didático - remover depois
void	print_sentence_teste(t_sentence **lst_sentence)
{
	t_sentence	*tmp;
	char		**args;
	int			i;

	tmp = *lst_sentence;
	if (!tmp)
		return ;
	while (tmp)
	{
		args = tmp->args;
		i = 0;
		while (args[i])
		{
			ft_printf("print sentence args[%d]: %s\n", i, args[i]);
			i++;
		}
		args = NULL;
		ft_printf("sentence fd_i: %d\n", tmp->fd_i);
		ft_printf("sentence fd_o: %d\n", tmp->fd_o);
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
		if (data->pipe_count > 0 || data->redirect_count > 0)
		{
			open_pipe_reds(data);
			clean_reds_sentences(data->lst_sentence);
			ft_printf("\nSentences after open_pipe_reds() and cleaned up\n");
			ft_printf("\nOnly for didatics, need remove later\n");
			print_sentence_teste(&data->lst_sentence);
		}
	}
	ft_printf("\nNext steps execution.\n");
	free_shell (data);
}
