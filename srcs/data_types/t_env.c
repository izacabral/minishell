/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:57:04 by vchastin          #+#    #+#             */
/*   Updated: 2023/06/01 00:36:20 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_envsize(t_env *env)
{
	int	nodes;

	if (env->size)
		return ;
	env->size = malloc(sizeof(*env->size));
	protect_malloc((void *)env->size);
	nodes = 1;
	while (env->next)
	{
		env->next->size = env->size;
		env = env->next;
		nodes++;
	}
	*env->size = nodes;
	printf("nodes: %i\n", *env->size);
}

/*
 * Input			:char *key - environment variable key
 *					:char *value - environment variable value
 *					:char size - amount of environment variable
 * Scope			:adding the key and value in a new node
 * Output			:a new node with the data from env
 */
t_env	*new_env(char *key, char *value)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	protect_malloc(node);
	node->key = ft_strdup(key);
	node->value = ft_strtrim(value, "'");
	node->next = NULL;
	node->size = NULL;
	return (node);
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - environment variable key
 *					:char *value - environment variable kvalue
 * Scope			:creating a new node
 * Output			:add keys and values to the node
 */
t_env	*addfront_env(t_env *env, char *key, char *value)
{
	t_env	*new;

	new = new_env(key, value);
	if (env == NULL)
		env = new;
	else
	{
		new->next = env;
		env = new;
	}
	if (env->size)
		*env->size += 1;
	return (env);
}

void	envdel_one(t_env *node)
{
	free(node->key);
	free(node->value);
	if (node->size && *node->size == 1)
		free(node->size);
	else if (node->size)
		*node->size -= 1;
	node->size = NULL;
	free(node);
}

/*
 * Input			:t_env - envp list
 * Scope			:clear env list
 * Output			:none
 */
void	clear_env(t_env *env)
{
	t_env	*node;

	while (env)
	{
		node = env->next;
		*env->size -= 1;
		if (!*env->size)
			free(env->size);
		env->size = NULL;
		envdel_one(env);
		env = node;
	}
}
