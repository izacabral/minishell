/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:50:05 by vchastin          #+#    #+#             */
/*   Updated: 2023/05/23 08:51:04 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:char *str - environment variable in wrong format
 *					:char *key - string that was split (environment variable key
 * Scope			:checks that the key is in the correct format
 *                  :if the key exists in the env list delete the node
 */
static void	unset(t_env *env, char *key)
{
	t_env	*node;
	t_env	*new;
	int		prev;

	node = compare_key(env, key);
	new = env;
	if (new == NULL || node == NULL)
		return ;
	prev = 0;
	while (new)
	{
		if (new == node || new->next == node)
		{
			if (prev == 0)
				env = node->next;
			new->next = node->next;
			del_one(node);
			break ;
		}
		prev = 1;
		new = new->next;
	}
	env->size--;
}

/*
 * Input			:int size - amount of arguments
 *					:char *str[] - arguments (command unset and/or enviroment variable)
 *					:Example: argv[0] = unset - argv[1] = students
 * Scope			:check key match
 */
int	unset_builtins(int size, char *str[], t_shell data)
{
	int	i;

	i = 0;
	if (size <= 1)
		return (0);
	while (++i < size)
	{
		if (check_unset(str[i]))
			unset(data.lst_env, str[i]);
	}
	return (0);
}
