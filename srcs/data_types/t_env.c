/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:57:04 by vchastin          #+#    #+#             */
/*   Updated: 2023/05/23 08:57:06 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:void *arg - argument can be of any type
 * Scope			:checks whether dynamic memory allocation has occurred
 * Output			:none
 * 					:or
 * 					:error and exit
 */
void	protect_malloc(void *arg)
{
	if (arg == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(errno);
	}
}

/*
 * Input			:char *key - environment variable key
 *					:char *value - environment variable value
 *					:char size - amount of environment variable
 * Scope			:adding the key and value in a new node
 * Output			:a new node with the data from env
 */
t_env	*new_env(char *key, char *value, int size)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	protect_malloc(node);
	node->key = ft_strdup(key);
	node->value = ft_strtrim(value, "'");
	node->next = NULL;
	node->size = size;
	return (node);
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - environment variable key
 *					:char *value - environment variable kvalue
 * Scope			:creating a new node
 * Output			:add keys and values to the node
 */
t_env	*add_env(t_env *env, char *key, char *value)
{
	t_env	*new;

	new = new_env(key, value, 0);
	if (env == NULL)
		env = new;
	else
	{
		new->next = env;
		env = new;
	}
	return (env);
}

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
