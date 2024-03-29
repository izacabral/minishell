/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:44:17 by bda-silv          #+#    #+#             */
/*   Updated: 2023/06/22 01:56:11 by daolivei         ###   ########.fr       */
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
	if (RL_ISSTATE(RL_STATE_READCMD))
		ioctl(1, TIOCSTI, "\n");
	else
		write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	g_global = 130;
	(void)signum;
}
