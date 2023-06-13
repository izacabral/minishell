/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe_reds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:28:57 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/11 21:32:16 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
// make real open_pipe
int	*open_pipe(t_sentence *actual, t_sentence *next)
{
	char	**argsp;
	char	**argsa;
	int		i;

	ft_printf("\nopen_pipe() - just checking\n");
	argsp = previous->args;
	i = 0;
	while (argsp[i])
	{
		ft_printf("argspipep[%d]: %s\n", i, argsp[i]);
		i++;
	}
	argsa = after->args;
	i = 0;
	while (argsa[i])
	{
		ft_printf("argspipea[%d]: %s\n", i, argsa[i]);
		i++;
	}
	return (0);
}
 */

/*
 * Fn		: set_reds_array(t_sentence *s, int **reds, int *index)
 * Scope	: if sentence has redirect calls open_reds() and set the reds array
 * Input	: a sentence node, a pointer to reds array and the array index;
 * Output	: void
 * Errors	: not applicable
 * Uses		: open_pipes_reds()
 */
static void	set_reds_array(t_sentence *s, int *reds, int *index)
{
	t_tkn	t;
	int		i;

	i = 0;
	ft_printf("\nset_reds_array()\n");
	while (s->args[i])
	{
		t = which_delim(s->args[i]);
		if (t > PIPE)
		{
			ft_printf("s->args[%d]: %s\n", i, s->args[i]);
			i++;
			reds[*index] = open_reds(t, s, s->args[i]);
			ft_printf("reds[%d]: %d\n", *index, reds[*index]);
			ft_printf("filename: %s\n", s->args[i]);
			(*index)++;
			ft_printf("(*index)++: %d\n", *index);
		}
		i++;
	}
}

/*
 * Fn		: open_pipe_reds(t_shell *data)
 * Scope	: traverse the sentences and call the functions open_reds and
 *				open_pipes filling their respective arrays in the t_shell
 * Input	: t_shell * - pointer to the global struct
 * Output	: int to show error
 * Errors	: -1 if there aren't any sentence
 * Uses		: launch_prog()
 */
int	open_pipe_reds(t_shell *data)
{
	t_sentence	*tmp_sentence;
	int			i_reds;
	int			i_pipes;

	tmp_sentence = data->lst_sentence;
	i_reds = 0;
	i_pipes = 0;
	if (!tmp_sentence)
		return (-1);
	while (tmp_sentence && data->redirect_count > 0)
	{
		if (tmp_sentence->reds_inside > 0)
			set_reds_array(tmp_sentence, data->reds, &i_reds);
		tmp_sentence = tmp_sentence->next;
	}
	tmp_sentence = data->lst_sentence;
	while (tmp_sentence && tmp_sentence->next)
	{
		data->pipes[i_pipes++] = open_pipe(tmp_sentence, tmp_sentence->next);
		tmp_sentence = tmp_sentence->next;
	}
	return (0);
}