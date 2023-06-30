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

/*
 * Fn		: exec_command(char *comm, char **args, t_shell *data)
 * Scope	: interface para executar comandos builtins ou por execve
 * Input	: char * - string com o nome do comando
 *			: char ** - argumentos a serem passados
 *			: t_shell * - ponteiro para estrutura global
 * Output	: int - mesmo retornos dos comandos
 * Errors	: dependente dos comandos
 * Uses		: [WIP] a ser integrado.
 */
void	exec_command(char *comm, char **args, t_shell *data)
{
	t_builtin	builtin;
	t_env		*path;
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
		path = compare_key(data->lst_env, "PATH");
		if (call_execve(args, path->value, envs) == -1)
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
