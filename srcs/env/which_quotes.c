/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:29:51 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/14 16:29:52 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_quotes	which_quotes(char c)
{
	if (c == '\'')
		return (SINGLE);
	if (c == '\"')
		return (DOUBLE);
	return (NONE);
}
