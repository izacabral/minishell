/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:13:30 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/18 14:54:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, fd);
	free(path);
	path = NULL;
	return (0);
}
