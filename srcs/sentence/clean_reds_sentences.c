/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_reds_sentences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:26:30 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/11 15:56:39 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arr_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

static int	arr_size_noreds(char **array)
{
	int	size;
	int	i;

	size = arr_size(array);
	i = 0;
	while (array[i])
	{
		if (which_delim(array[i]) > PIPE)
			size -= 2;
		i++;
	}
	return (size);
}

static char	**clean_arr(char **array)
{
	int		new_size;
	char	**clean_args;
	int		i;

	new_size = arr_size_noreds(array);
	clean_args = malloc (sizeof(char *) * (new_size + 1));
	if (!clean_args)
		return (NULL);
	i = 0;
	new_size = 0;
	while (array[i])
	{
		while (array[i] && which_delim(array[i]) > PIPE)
			i += 2;
		if (array[i])
		{
			clean_args[new_size] = ft_strdup(array[i]);
			new_size++;
			i++;
		}
	}
	clean_args[new_size] = NULL;
	return (clean_args);
}

/*
 * Fn		: clean_reds_sentences(t_shell *data)
 * Scope	: loops through the list of sentences and if sentences
 *				has redirect remove it and its file name
 * Input	: t_shell *data
 * Output	: void
 * Errors	: not applicable
 * Uses		: wip
 */
void	clean_reds_sentences(t_shell *data)
{
	t_sentence	*tmp_sentencelst;
	char		**tmp;

	tmp_sentencelst = data->lst_sentence;
	if (!data->lst_sentence)
		return ;
	while (data->lst_sentence)
	{
		if (data->lst_sentence->reds_inside > 0)
		{
			tmp = data->lst_sentence->args;
			data->lst_sentence->args = clean_arr(data->lst_sentence->args);
			free_array(tmp);
		}
		data->lst_sentence = data->lst_sentence->next;
	}
	data->lst_sentence = tmp_sentencelst;
}
