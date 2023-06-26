/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:47:32 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 17:18:31 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//After a call to execve() the signals action are reset to default.
//SIGQUIT is set to be ignored here, but this might need to be changed,
// as CTRL+D can be used to quit a command in execution.
/*
 * Fn		: setup_signals(void)
 * Scope	: setup the signals for interactive mode
 *			: SIGINT (Ctrl + C) is set to int_handler function
 *			: SIGQUIT (Ctrl + \) is set to be ignored
 * Input	: void
 * Output	: void
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
void	setup_signals(void)
{
	struct sigaction	int_action;
	struct sigaction	quit_action;

	sigemptyset(&int_action.sa_mask);
	sigemptyset(&quit_action.sa_mask);
	int_action.sa_handler = &int_handler;
	int_action.sa_flags = 0;
	quit_action.sa_handler = SIG_IGN;
	quit_action.sa_flags = 0;
	sigaction(SIGINT, &int_action, NULL);
	sigaction(SIGQUIT, &quit_action, NULL);
}
