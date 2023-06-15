/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandvars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:29:34 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/14 21:19:03 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"

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
	int		i;
	t_tkn	t;

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
}
