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
 * Fn		: get_token_word(t_token **lst_token)
 * Scope	: loops through the token list and returns the next node in the
 *				token list of type word or null
 * Input	: t_token ** token list
 *
 * Output	: t_token of word or null type token list node
 * Errors	: not applicable
 *
 * Uses		: tkn_to_sentence(t_token **lst_token)
 */
static t_token	*get_token_word(t_token **lst_token)
{
	if (!(*lst_token))
		return (NULL);
	while ((*lst_token)->next && (*lst_token)->tkn != WORD)
		*lst_token = (*lst_token)->next;
	if ((*lst_token)->tkn != WORD)
		return (NULL);
	return (*lst_token);
}

/*
 * Fn		: count_tkn_words(t_token **lst_token)
 * Scope	: loops through the token list and counting word nodes
 *
 * Input	: t_token ** token list
 *
 * Output	: the numbers of word nodes or 0 if none
 * Errors	: not applicable
 *
 * Uses		: tkn_to_sentence(t_token **lst_token)
 */
static size_t	count_tkn_words(t_token **lst_token)
{
	size_t	count;
	t_token	*tmp;

	count = 0;
	tmp = get_token_word(&(*lst_token));
	if (!(tmp))
		return (count);
	while (tmp && tmp->tkn == WORD)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/*
 * Fn		: tkn_to_sentence(t_token **lst_token)
 * Scope	: loop through list of tokens and create char **
 *				for list of sentences
 * Input	: t_token ** token list
 *
 * Output	: char ** for list of sentences
 * Errors	: not applicable
 *
 * Uses		: create_sentences(t_env *env, t_token **lst_token, \
 				t_sentence **lst_sentence)
 */
char	**tkn_to_sentence(t_token **lst_token)
{
	t_token	*tmp;
	size_t	size;
	char	**args;
	size_t	i;

	tmp = get_token_word(&(*lst_token));
	size = count_tkn_words(&tmp);
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (NULL);
	args[size] = NULL;
	i = 0;
	while (i < size)
	{
		args[i] = ft_strdup(tmp->word);
		i++;
		tmp = tmp->next;
	}
	return (args);
}
