/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:37:16 by vchastin          #+#    #+#             */
/*   Updated: 2023/06/02 03:07:22 by daolivei         ###   ########.fr       */
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
	char	**dict_split;
	t_env	*env;

	index = 0;
	env = NULL;
	dict_split = NULL;
	while (environ[index])
	{
		dict_split = ft_split(environ[index], '=');
		env = addfront_env(env, dict_split[0], dict_split[1]);
		freetab((void **)dict_split);
		dict_split = NULL;
		index++;
	}
	set_envsize(env);
	return (env);
}
