#include "minishell.h"

static void		copy_path(t_string **lst, char *path, size_t size);

/*
 * Fn		: path_to_lst(char *path)
 * Scope	: transforma a string da variável PATH em uma lista encadeada
 * Input	: char * - variável PATH
 * Output	: t_string *
 * Errors	: NULL - erro durante a criação da lista, ou path é NULL
 * Uses		: call_execve (call_execve.c) [possibilidade de guardar a lista já na t_shell, para não ser necessário criá-la a cada chamada do execve]
 */
t_string	*path_to_lst(char *path)
{
	t_string		*lst;
	unsigned int	i;

	if (!path)
		return (NULL);
	lst = NULL;
	while (*path)
	{
		i = 0;
		while (path[i] && path[i] != ':')
			i++;
		copy_path(&lst, path, i);
		path += i;
		if (*path)
			path++;
	}
	return (lst);
}

static void	copy_path(t_string **lst, char *path, size_t size)
{
	char	*str;

	str = ft_substr(path, 0, size);
	ft_stradd_back(lst, ft_strnew(str, size));
}
