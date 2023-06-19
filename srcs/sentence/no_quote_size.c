/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quote_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:27:19 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/10 22:27:23 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: no_quote_size(char *str)
 * Scope	: counts bytes that aren't quotes

 * Input	: the string that is being scanned
 * Output	: the number of bytes that aren't quotes
 * Errors	: not applicable
 *
 * Uses		: rem_str_quotes() and while_no_quotes()
 */
int	no_quote_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	return (i);
}
