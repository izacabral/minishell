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
static int	test_acess(char *pathname);

/*
 * Fn		: call_execve(char **argsm char *path)
 * Scope	: testa executável em args[0] e chama execve()
 * Input	: char ** - comando e argumentos a serem executados
 *			: char * - variável PATH
 *			: conversão facilita leitura e manipulação
 *			: alternativa possível à lista seria char **
 * Output	: int - 0 (sucesso)
 * Errors	: int - 1: não é um comando executável ou arquivo não existe
 * Uses		: [WIP] a ser integrado.
 */
// int	call_execve(char **args, char *path)
// {
// 	t_string	*p;

// 	p = path_to_lst(path);
// 	if (get_comm(&args[0], p))
// 	{
// 		ft_strclear(&p, free);
// 		return (1);
// 	}
// 	ft_strclear(&p, free);
// 	launch_command(args);
// 	return (0);
// }

int	call_execve(char **args, char *path)
{
	t_string	*p;

	p = path_to_lst(path);
	if (get_comm(&args[0], p))
	{
		ft_strclear(&p, free);
		return (1);
	}
	ft_strclear(&p, free);
	default_signals();
	if ((execve(*args, args, NULL)) == -1)
	{
		ft_putendl_fd("Error with execve\n", 2);
		g_global = errno;
	}
	setup_signals();
	return (0);
}

// testa args[0]
// se argumento já contiver caminho, testa como foi passado,
// caso contrário, testa segundo PATH
static int	get_comm(char **comm, t_string *path_lst)
{
	if (ispath(*comm))
	{
		if (!test_acess(*comm))
			return (0);
	}
	if (!test_command(comm, path_lst))
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

// Testa se arquivo existe e se é executável
// Pode integrar essa função depois com as mensagens de erro
static int	test_acess(char *pathname)
{
	if (access(pathname, X_OK))
		return (1);
	return (0);
}
