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
 * Fn		: while_no_quotes(char *str, int i,  char *new_str)
 * Scope	: joins the part of the string that has a quote
 *				without unwanted quotes
 * Input	: the string that is being scanned and the new string
 *				that should be without unwanted quotes
 * Output	: the  joined string without unwanted quotes
 * Errors	: not applicable
 *
 * Uses		: rem_str_quotes()
 */
char	*quotes_removed(char *str, int i, char *new_str)
{
	char	quote;
	char	*tmp;
	int		j;

	quote = str[i];
	tmp = NULL;
	j = 0;
	i++;
	while (str[i] && str[i] == quote)
		i++;
	j = quote_size(&str[i], quote);
	tmp = ft_substr(str, i, j);
	new_str = ft_strjoin_free(new_str, tmp);
	free(tmp);
	return (new_str);
}
