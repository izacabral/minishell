/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:27:07 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/10 22:27:12 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: new_index(char *str, int i)
 * Scope	: counts the new index that should be scanned

 * Input	: the string that is being scanned
 * Output	: the new index
 * Errors	: not applicable
 *
 * Uses		: rem_str_quotes()
 */
int	new_index(char *str, int i)
{
	char	quote;
	int		quote_count;
	int		total;
	int		j;

	quote = str[i];
	quote_count = 1;
	total = 0;
	j = 0;
	i++;
	while (str[i] && str[i] == quote)
	{
		if ((quote == '\'' && str[i + 1] == '\"') || \
			(quote == '\"' && str[i + 1] == '\''))
			break ;
		quote_count++;
		i++;
	}
	j = quote_size(&str[i], quote);
	total = i + j + quote_count;
	return (total);
}
