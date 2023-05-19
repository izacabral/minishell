/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:47:32 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/19 09:47:39 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//After a call to execve() the signals action are reset to default.
//SIGQUIT is set to be ignored here, but this might need to be changed,
// as CTRL+D can be used to quit a command in execution.
void	setup_signals(void)
{
	struct sigaction	int_action;
	struct sigaction	quit_action;

	sigemptyset(&int_action.sa_mask);
	sigemptyset(&quit_action.sa_mask);
	int_action.sa_handler = int_handler;
	quit_action.sa_handler = SIG_IGN;
	int_action.sa_flags = 0;
	quit_action.sa_flags = 0;
	sigaction(SIGINT, &int_action, NULL);
	sigaction(SIGQUIT, &quit_action, NULL);
}
