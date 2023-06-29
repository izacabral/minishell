/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:37:16 by vchastin          #+#    #+#             */
/*   Updated: 2023/06/28 14:37:19 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input		:char *environ[] - environment variable
 * Scope		:makes a copy of the env
 *				:remembering that environment variables have key=value format
 * Output		:a node with the data from env
 */

t_env	*get_env(char *environ[])
{
	int		index;
	char	*key;
	char	*value;
	t_env	*env;

	index = 0;
	env = NULL;
	while (environ[index])
	{
		key = NULL;
		value = NULL;
		get_entry(&key, &value, environ[index], ft_strlen(environ[index]));
		env = addfront_env(env, key, value);
		free(key);
		free(value);
		index++;
	}
	set_envsize(env);
	return (env);
}
