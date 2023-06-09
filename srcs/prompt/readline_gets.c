/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_gets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:47:13 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 17:31:40 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: readline_gets(char *line)
 * Scope	: get the output from readline() into buffer *line
 *			: if *line is not NULL, free it
 * Input	: char * - buffer
 * Output	: char * - return from readline
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
char	*readline_gets(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	line = readline("minishell > ");
	return (line);
}
