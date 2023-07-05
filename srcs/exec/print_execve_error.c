/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:27:17 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/30 18:41:16 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_execve_error(char *str, int error)
{
	if (error == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_global = 126;
	}
	else
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": command not found", 2);
		g_global = 127;
	}
}
