/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hdoc_sig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:54:56 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/25 22:54:59 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	int_handler_hdoc(int signum)
{
	g_global = 1;
	(void) signum;
}

void	setup_hdoc_sig(void)
{
	struct sigaction	exit_action;

	sigemptyset(&exit_action.sa_mask);
	exit_action.sa_handler = &int_handler_hdoc;
	exit_action.sa_flags = 0;
	sigaction(SIGINT, &exit_action, NULL);
}

