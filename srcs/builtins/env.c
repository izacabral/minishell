/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:49:46 by vchastin          #+#    #+#             */
/*   Updated: 2023/07/03 18:01:35 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:t_env *env - envp list(head)
 * Output			:print environment variables(envp list)
 * 					:Example: PATH=/usr/local/bin
 */
void	env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		ft_putstr_fd(tmp->key, 1);
		ft_putchar_fd('=', 1);
		if (tmp->value)
			ft_putstr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	ft_putstr_fd(tmp->key, 1);
	ft_putchar_fd('=', 1);
	if (tmp->value)
		ft_putstr_fd(tmp->value, 1);
	ft_putchar_fd('\n', 1);
}
