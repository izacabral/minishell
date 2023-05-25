/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:56:37 by vchastin          #+#    #+#             */
/*   Updated: 2023/05/23 08:56:39 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_one(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/*
 * Input			:t_env - envp list
 * Scope			:clear env list
 * Output			:none
 */
void	del_lst(t_env *env)
{
	t_env	*node;

	while (env)
	{
		node = env->next;
		del_one(env);
		env = node;
	}
}
