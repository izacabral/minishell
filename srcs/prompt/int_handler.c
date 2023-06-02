/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:44:17 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 17:11:49 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: int_handler(int signum)
 * Scope	: handler for INTERRUPT signal (Ctrl+C)
 * Input	: int - signal
 * Output	: void
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
void	int_handler(int signum)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signum;
}
