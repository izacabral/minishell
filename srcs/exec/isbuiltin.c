/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:26:00 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/22 19:26:01 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	isbuiltin(char *comm)
{
	if (!ft_strncmp(comm, "echo", 5))
		return (ECHO);
	if (!ft_strncmp(comm, "cd", 3))
		return (CD);
	if (!ft_strncmp(comm, "pwd", 4))
		return (PWD);
	if (!ft_strncmp(comm, "export", 7))
		return (EXPORT);
	if (!ft_strncmp(comm, "unset", 6))
		return (UNSET);
	if (!ft_strncmp(comm, "env", 4))
		return (ENV);
	if (!ft_strncmp(comm, "exit", 5))
		return (EXIT);
	return (ENOBLTN);
}
