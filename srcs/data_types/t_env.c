/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:57:04 by vchastin          #+#    #+#             */
/*   Updated: 2023/07/03 18:20:29 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	node->value = ft_strdup(value);
	node->next = NULL;
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
	return (env);
}

void	envdel_one(t_env *node)
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
void	clear_env(t_env **env)
{
	t_env	*node;

	while (*env)
	{
		node = *env;
		*env = (*env)->next;
		envdel_one(node);
		node = NULL;
	}
}
