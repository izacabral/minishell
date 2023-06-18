/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:18:32 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/18 12:11:42 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_oldpwd(t_shell *data)
{
	char	*ptr;
	char	*oldpwd;

	ptr = getcwd(NULL, 0);
	oldpwd = ft_strjoin("OLDPWD=", ptr);
	export(1, &oldpwd, data->lst_env);
	free(ptr);
	free(oldpwd);
}

static void	set_pwd(t_shell *data)
{
	char	*ptr;
	char	*pwd;

	ptr = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", ptr);
	unset(1, &pwd, &data->lst_env);
	export(1, &pwd, data->lst_env);
	free(ptr);
	free(pwd);
}

static char	*get_home(t_shell *data)
{
	t_env	*home;

	home = compare_key(data->lst_env, "HOME");
	return (home->value);
}

static int	change_dir(char *path, t_shell *data)
{
	if (!path)
	{
		path = get_home(data);
		if (!path)
		{
			ft_putendl_fd("minishell: cd: HOME not set", 1);
			return (1);
		}
		set_oldpwd(data);
		chdir(path);
		set_pwd(data);
		return (0);
	}
	if (chdir(path) == -1)
	{
		ft_printf("minishel: cd: %s: No such file or directory", path);
		return (1);
	}
	set_pwd(data);
	return (0);
}

int	cd(int argc, char **argv, t_shell *data)
{
	if (argc > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", 1);
		return (1);
	}
	return (change_dir(argv[1], data));
}
