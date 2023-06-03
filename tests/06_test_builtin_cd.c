/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:21:41 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:05 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	set_oldpwd(t_shell data)
{
	char	*ptr;
	char	*oldpwd;

	ptr = getcwd(NULL, 0);
	oldpwd = ft_strjoin("OLDPWD=", ptr);
	unset_builtins(1, &oldpwd, data);
	export_builtins(1, &oldpwd, data);
	free(ptr);
	free(oldpwd);
}

void	set_pwd(t_shell data)
{
	char	*ptr;
	char	*pwd;

	ptr = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", ptr);
	unset_builtins(1, &pwd, data);
	export_builtins(1, &pwd, data);
	free(ptr);
	free(pwd);
}

char	*get_home(t_shell data)
{
	t_env	*home;

	home = compare_key(data.lst_env, "HOME");
	return (home->value);
}

int	cd(t_shell data, char *path)
{
	int	ret;

	set_oldpwd(data);
	if (!path)
	{
		if (!get_home(data))
		{
			printf("minishel: cd: HOME not set\n");
			return (ret = 1);
		}
		else
			chdir(get_home(data));
	}
	else
	{
		if (chdir(path) == -1)
		{
			printf("minishel: cd: %s: No such file or directory", path);
			return (ret = 1);
		}
	}
	set_pwd(data);
	return (0);
}

int	test_cd(t_shell data)
{
	int		ret;
	char	*ptr;
	
	ptr = NULL;
	if (cd(data, ptr) == 1)
		return (ret = 1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	data;
	(void)(av);
	(void)(ac);

	init_shell(&data, envp);
	if (test_cd(data) == -1)
		return (1);
	del_lst(data.lst_env);
	return (0);
}
