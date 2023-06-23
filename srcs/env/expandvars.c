/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandvars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:29:34 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/22 21:54:17 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rearrange_args(int size, char **args);
static void	pushback(char **array, int index, int end);

/*
 * Fn		: expandvars(char **sentences, t_env *env)
 * Scope	: reads array of strings and applies expansions
 * Input	: char ** - array of strings
 *			: t_env * - list of environment variables
 * Output	: void
 * Errors	: not applicable
 * Uses		: create_sentences()
 */
void	expandvars(char **sentences, t_env *env)
{
	const int	size = args_size(sentences);
	int			i;
	t_tkn		t;

	i = 0;
	while (sentences[i])
	{
		t = which_delim(sentences[i]);
		if (t > WORD)
			i++;
		if (t != HDOC)
			sentences[i] = expand_sentence(&sentences[i], env, 0);
		i++;
	}
	rearrange_args(size, sentences);
}

void	expand_hdoc_var(char **sentence, t_env *env)
{
	*sentence = expand_sentence(sentence, env, 1);
}

static void	rearrange_args(int size, char **args)
{
	int		i;
	int		j;

	i = 0;
	j = size;
	while (i < j)
	{
		if (!args[i] && i < j - 1)
		{
			pushback(args, i, j - 1);
			j--;
		}
		i++;
	}
}

static void	pushback(char **array, int index, int end)
{
	int	after;

	while (index < end)
	{
		after = index + 1;
		swap_ptr(&array[index], &array[after]);
		index++;
	}
}
