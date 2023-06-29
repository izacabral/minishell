/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:41:43 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/22 03:31:05 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_comm(char **comm, t_string *path_lst);
static int	ispath(char *s);
static int	test_command(char **comm, t_string *path_lst);
static int	test_access(char *pathname);

/*
 * Fn		: call_execve(char **argsm char *path)
 * Scope	: turns args[0] into absolute if it is an exexutable command
 *				and executes execve
 * Input	: char ** - sentence args
 *			: char * - env path value
 * Output	: void
 * Errors	: n.a.
 * Uses		: exec_command()
 */
int	call_execve(char **args, char *path, char **envs)
{
	t_string	*p;

	p = path_to_lst(path);
	if (!get_comm(&args[0], p))
	{
		ft_putstr_fd(*args, 2);
		ft_putendl_fd(": command not found", 2);
		ft_strclear(&p, free);
		return (-1);
	}
	if ((execve(*args, args, envs)) == -1)
	{
		print_executor_error(*args);
		return (-1);
	}
	return (0);
}

static int	get_comm(char **comm, t_string *path_lst)
{
	if (ispath(*comm))
	{
		if(test_access(*comm))
			return (1);
	}
	else
	{
		if (test_command(comm, path_lst))
			return (1);
	}
	return (0);
}

static int	ispath(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (1);
		s++;
	}
	return (0);
}

static int	test_command(char **comm, t_string *path_lst)
{
	char	*path;
	char	*aux;

	aux = ft_strdup(*comm);
	prefix_slash(&aux);
	while (path_lst)
	{
		path = ft_strjoin(path_lst->content, aux);
		if (test_access(path))
		{
			free(aux);
			free(*comm);
			*comm = NULL;
			*comm = path;
			return (1);
		}
		free(path);
		path = NULL;
		path_lst = path_lst->next;
	}
	free(aux);
	return (0);
}

static int	test_access(char *pathname)
{
	if (!access(pathname, X_OK))
		return (1);
	return (0);
}
