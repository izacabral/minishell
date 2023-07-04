/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stash_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:28:21 by izsoares          #+#    #+#             */
/*   Updated: 2023/07/04 17:30:09 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: stash_string(t_string **lst, char *sentence, int size)
 * Scope	: stores the string up to the character before $
 * Uses		: split_sentence()
 */
void	stash_string(t_string **lst, char *sentence, int size)
{
	char	*to_stash;

	to_stash = ft_substr(sentence, 0, size);
	if (to_stash && *to_stash)
		ft_stradd_back(lst, ft_strnew(to_stash, size));
}
