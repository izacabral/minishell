/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:26:15 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/22 17:26:18 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	isbuiltin(char *comm)
{
	if (!comm)
		return (ENOBLTN);
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
