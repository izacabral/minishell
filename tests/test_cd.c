/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:28:08 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/22 03:22:36 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

/*
 * cd = changes directory
 * brief: changes from the actual dir to the dir specified in path
 * and updates the env variables PWD and OLD_PDW
 * t_env *env: a pointer to a struct containing the PWD and OLD_PWD
 * vars
 * char *path: pointer to a string with a designed path
 *
*/

typedef struct s_env
{
	char	*pwd;
	char	*old_pwd;
	char	*home;
}				t_env;

static int	check_ptr(char *ptr)
{
	if (!ptr)
	{
		free(ptr);
		return (1);
	}
	return (0);
}

static void	clear_memory(t_env *env)
{
	if (env->pwd)
	{
		free(env->pwd);
		env->pwd = NULL;
	}
	if (env->old_pwd)
	{
		free(env->old_pwd);
		env->old_pwd = NULL;
	}
}

static int	change_dir(t_env *env, char *path)
{
	char	*ptr;

	ptr = NULL;
	clear_memory(env);
	ptr = getcwd(NULL, 0);
	if (check_ptr(ptr))
		return (1);
	else
	{
		env->old_pwd = ft_strdup(ptr);
		free(ptr);
	}
	chdir(path);
	ptr = getcwd(NULL, 0);
	if (check_ptr(ptr))
		return (1);
	else
	{
		env->pwd = ft_strdup(ptr);
		free(ptr);
	}
	return (0);
}

int	cd(t_env *env, char *path)
{
	if (!path)
		printf("%s\n", env->home);
	else
		change_dir(env, path);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (1);
	env->home = ft_strdup("home/dmatavel");
	env->old_pwd = ft_strdup("old_path");
	if (ac > 1 || ac < 3)
	{
		if (cd(env, av[1]) != 0)
			return (1);
		free(env->pwd);
		free(env->old_pwd);
		free(env->home);
		free(env);
	}
	return (0);
}
