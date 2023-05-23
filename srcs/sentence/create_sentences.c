/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:08:15 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/21 20:08:18 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: get_not_word(t_token **lst_token)
 * Scope	: loops through the token list and returns the next node in the
 *				token list of type != word or null
 * Input	: t_token ** token list
 *
 * Output	: t_token of != word or null type token list node
 * Errors	: not applicable
 *
 * Uses		: create_sentences(t_env *env, t_token **lst_token, \
 				 t_sentence **lst_sentence)
 */
static t_token	*get_not_word(t_token **lst_token)
{
	if (!(*lst_token))
		return (NULL);
	while ((*lst_token) && (*lst_token)->tkn == WORD)
		*lst_token = (*lst_token)->next;
	return (*lst_token);
}

/*
 * Fn		: create_sentences(t_env *env, t_token **lst_token,
 *				 t_sentence **lst_sentence)
 * Scope	: loops through the list of tokens to create the list
 *				of sentences with the variables already expanded
 *				and without quotes
 *
 * Input	: t_env *env, t_token **lst_token, t_sentence **lst_sentence
 *
 * Output	: void
 * Errors	: not applicable
 *
 * Uses		:
 */
void create_sentences(t_env *env, t_token **lst_token, t_sentence **lst_sentence)
{
	char	**args;

	while (*lst_token)
	{
		args = tkn_to_sentence(&(*lst_token));
		expandvars(args, env);
		remove_quotes(args);
		addback_sentence(&(*lst_sentence), new_sentence(args));
		*lst_token = get_not_word(&(*lst_token));
	}
}

