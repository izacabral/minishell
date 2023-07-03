/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:49:52 by vchastin          #+#    #+#             */
/*   Updated: 2023/07/03 18:21:43 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - value that will be placed in the list envp
 *					:char *value - value that will be placed in the list envp
 *					:char *str - argument (enviroment variable)
 * Scope       		:adding new environment variable in envp list
 */
static void	append_env(t_env *env, char *key, char *value)
{
	while (env->next)
		env = env->next;
	env->next = new_env(key, value);
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *value - value that will be placed in the list envp
 *					:char *str - argument (enviroment variable)
 * Scope       		:exchange of envp list value element
 */
static void	modify_env(t_env *env, char *value)
{
	free(env->value);
	env->value = ft_strdup(value);
}

/*
 * Check key entry
 * valid key is <name=>
 * invalid key is <name>
 */
static int	check_entry(char *entry)
{
	while (*entry)
	{
		if (*entry == '=')
			return (0);
		entry++;
	}
	return (1);
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
static void	add_export(t_env **env, char *str)
{
	t_env	*new;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (check_entry(str))
		return ;
	get_entry(&key, &value, str, ft_strlen(str));
	if (!check_varname(key))
	{
		free(key);
		free(value);
		export_error(str);
		return ;
	}
	new = compare_key(*env, key);
	if (new)
		modify_env(new, value);
	else if (*env)
		append_env(*env, key, value);
	else
		*env = new_env(key, value);
	free(key);
	free(value);
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
int	export(int size, char *str[], t_env **env)
{
	int		i;

	i = 0;
	if (size == 1)
	{
		print_export(*env);
		return (0);
	}
	while (++i < size)
		add_export(env, str[i]);
	return (0);
}
