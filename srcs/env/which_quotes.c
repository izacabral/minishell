/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:29:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/07/03 18:25:03 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quotes	which_quotes(char c)
{
	if (c == '\'')
		return (SINGLE);
	if (c == '\"')
		return (DOUBLE);
	return (NONE);
}
