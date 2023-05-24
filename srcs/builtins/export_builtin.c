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

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - value that will be placed in the list envp
 *					:char *value - value that will be placed in the list envp
 *					:char *str - argument (enviroment variable)
 * Scope       		:adding new environment variable in envp list
 */
static void	append_env(t_env *env, char *key, char *value, char *str)
{
	while (env->next)
		env = env->next;
	if (value == NULL && ft_strchr(str, '='))
		value = "";
	env->next = new_env(key, value, env->size);
	env->size++;
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *value - value that will be placed in the list envp
 *					:char *str - argument (enviroment variable)
 * Scope       		:exchange of envp list value element
 */
static void	modify_env(t_env *env, char *value, char *str)
{
	if (value)
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
	else if (ft_strchr(str, '='))
	{
		free(env->value);
		env->value = ft_strdup("");
	}
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *str - argument (enviroment variable)
 * Scope			:checks if the first character is in the correct format
 *       			:separates the string from the equal sign (=)
 *                  :in the conditional structure it is checked if the key
 * 					already exists in the envp list
 * 					:calls functions that will manipulate and check the format of the string
 * 					that was split
 */
static void	add_export(t_env *env, char *str)
{
	char	**dict_split;
	t_env	*new;

	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		export_error(str);
		return ;
	}
	dict_split = ft_split(str, '=');
	new = compare_key(env, dict_split[0]);
	if (new == NULL && check_export(dict_split[0], str))
		append_env(env, dict_split[0], dict_split[1], str);
	else if (new != NULL)
		modify_env(new, dict_split[1], str);
	free_array(dict_split);
}

/*
 * Input			:int size - amount of arguments
 *					:char *str[] - arguments (command export and/or enviroment variable)
 *					:Example: argv[0] = export - argv[1] = students=vanessa;
 * size=1			:argument 1 (export)
 * size=2			:argument 1 (export) + argument 2 (environment variable)
 * ...
 * Output			:print environment variables in order with 'declare -x'
 * 					:or
 * 					:add a new environment variable (if true)
 */
int	export_builtins(int size, char *str[], t_shell data)
{
	int		i;

	i = 0;
	if (size == 1)
	{
		print_export(data.lst_env);
		return (0);
	}
	while (++i < size)
		add_export(data.lst_env, str[i]);
	return (0);
}
