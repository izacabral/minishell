/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:37:16 by vchastin          #+#    #+#             */
/*   Updated: 2023/06/11 13:24:21 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	get_entry(char **key, char **value, char *var, int len);

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

void	get_entry(char **key, char **value, char *var, int len)
{
	int	i;

	i = 0;
	while (var[i] != '=')
		i++;
	*key = ft_substr(var, 0, i);
	i++;
	*value = ft_substr(var, i, len - i);
}
