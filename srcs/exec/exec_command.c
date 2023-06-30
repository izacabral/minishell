/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:09:25 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/20 00:09:27 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**env_to_array(t_env *lst);
static char	*get_path(t_shell *data);

/*
 * Fn		: exec_command(char *comm, char **args, t_shell *data)
 * Scope	: executes commands, either builtin or through execve
 * Input	: char * - command name
 *			: char ** - command arguments
 *			: t_shell * - pointer to global struct
 * Output	: int - same as commands
 * Errors	: same as commands
 * Uses		: exec_sentence [executor.c]
 */
void	exec_command(char *comm, char **args, t_shell *data)
{
	t_builtin	builtin;
	char		*path;
	char		**envs;

	builtin = isbuiltin(comm);
	if (builtin)
	{
		call_builtin(args, data, builtin);
		free_shell(data);
		clear_env(&data->lst_env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		envs = env_to_array(data->lst_env);
		path = get_path(data);
		if (call_execve(args, path, envs) == -1)
		{
			free_array(envs);
			exit(127);
		}
	}
}

static char	**env_to_array(t_env *lst)
{
	t_env	*tmp;
	char	*env_str;
	char	**env_array;

	tmp = lst;
	env_str = NULL;
	while (tmp)
	{
		env_str = ft_strjoin_free(env_str, tmp->key);
		env_str = ft_strjoin_free(env_str, "=");
		env_str = ft_strjoin_free(env_str, tmp->value);
		env_str = ft_strjoin_free(env_str, "\n");
		tmp = tmp->next;
	}
	env_array = ft_split(env_str, '\n');
	free(env_str);
	return (env_array);
}

static char	*get_path(t_shell *data)
{
	t_env	*path;
	char	*p;

	path = compare_key(data->lst_env, "PATH");
	if (!path)
		p = NULL;
	else
		p = path->value;
	return (p);
}
