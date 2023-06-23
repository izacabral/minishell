/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_sentence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:29:06 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/22 20:46:19 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: expand_sentence(char **sentence, t_env *env)
 * Scope	: reads a string and applies expansions.
 *				The old string, if expanded, is released
 * Input	: char ** - string address
 *			: t_env * - list of environment variables
 * Output	: char * - a new allocated string with the expansions applied;
 *			:		 - the unmodified string if no expansion found
 * Errors	: not applicable
 * Uses		: expandvars()
 */
char	*expand_sentence(char **sentence, t_env *env, int hdoc)
{
	char		*new;
	char		*old;
	t_string	*tmp;

	old = *sentence;
	tmp = scan_sentence(old, env, hdoc);
	if (!tmp)
		return (old);
	new = ft_lst_to_str(tmp);
	ft_strclear(&tmp, free);
	free(old);
	return (new);
}
