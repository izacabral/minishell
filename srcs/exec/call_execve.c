#include "libft.h"
#include "minishell.h"
#include <unistd.h>

static int	get_prog(char **prog, t_string *path_lst);
static int	ispath(char *s);

int	call_execve(char **args, char *path)
{
	t_string	*path_lst;

	path_lst = path_to_lst(path);
	return (0);
}

static int	get_prog(char **prog, t_string *path_lst)
{
	char	*output;

	if (ispath(*prog))
	{
		//test executable
	}
	// test path
}

static int	ispath(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (1);
	}
	return (0);
}
