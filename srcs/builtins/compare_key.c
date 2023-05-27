/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:49:52 by vchastin          #+#    #+#             */
/*   Updated: 2023/05/23 08:52:33 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - element to be compared
 * Scope			:compares if the key of the argument is the same
 * 					as the environment variable
 * Output			:existing key in the environment variable
 * 					:or
 * 					:NULL
 */
t_env	*compare_key(t_env *env, char *key)
{
	t_env	*node;

	node = env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
