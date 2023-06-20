/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:10:25 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/09 00:10:27 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	default_signals(void)
{
	struct sigaction	dfl;

	dfl.sa_handler = SIG_DFL;
	sigaction(SIGINT, &dfl, NULL);
	sigaction(SIGQUIT, &dfl, NULL);
}
