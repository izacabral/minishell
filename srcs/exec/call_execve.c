#include "libft.h"
#include "minishell.h"
#include "types.h"
#include <stdlib.h>

static int	get_prog(char **prog, t_string *path_lst);
static int	ispath(char *s);
static int	test_command(char **comm, t_string *path_lst);
static int	test_acess(char *pathname);

int	call_execve(char **args, char *path)
{
	t_string	*path_lst;

	path_lst = path_to_lst(path);
	if (get_prog(&args[0], path_lst))
	{
		ft_strclear(&path_lst, free);
		return (1);
	}
	ft_strclear(&path_lst, free);
	return (0);
}

static int	get_prog(char **prog, t_string *path_lst)
{
	if (ispath(*prog))
	{
		if (!test_acess(*prog))
			return (0);
	}
	if (!test_command(prog, path_lst))
		return (0);
	return (1);
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
		if (!test_acess(path))
		{
			free(aux);
			free(*comm);
			*comm = NULL;
			*comm = path;
			return (0);
		}
		free(path);
		path = NULL;
		path_lst = path_lst->next;
	}
	free(aux);
	return (1);
}

static int	test_acess(char *pathname)
{
	if (access(pathname, X_OK))
		return (1);
	return (0);
}
