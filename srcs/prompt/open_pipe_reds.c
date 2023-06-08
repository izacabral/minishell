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

// make real open_pipe
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

// make real open_reds
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

/*
 * Fn		: set_reds_array(t_sentence *s, int **reds, int *index)
 * Scope	: if sentence has redirect calls open_reds() and set the reds array
 * Input	: a sentence node, a pointer to reds array and the array index;
 * Output	: void
 * Errors	: not applicable
 * Uses		: open_pipes_reds()
 */
static void	set_reds_array(t_sentence *s, int **reds, int *index)
{
	t_tkn	t;
	int		i;

	i = 0;
	while (s->args[i])
	{
		if ((t = which_delim(s->args[i])))
		{
			i++;
			*reds[*index] = open_reds(t, s, s->args[i]);
			(*index)++;
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
			set_reds_array(tmp_sentence, &data->reds, &i_reds);
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
