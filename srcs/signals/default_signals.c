/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:10:25 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/22 03:30:31 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	default_signals(void)
{
	struct sigaction	dfl;

	sigemptyset(&dfl.sa_mask);
	dfl.sa_flags = 0;
	dfl.sa_handler = SIG_DFL;
	sigaction(SIGINT, &dfl, NULL);
}
