/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:13:30 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/15 14:42:08 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	pwd(void)
{
	if (getcwd(NULL, 0) != NULL)
		ft_printf("%s\n", getcwd(NULL, 0))
	else
		return (1);
	return (0);
	/*
	char	*abs_path;
	int		len;

	len = ft_srlen(getcwd(NULL, 0));
	abs_path = malloc(sizeof(char) * len + 1);
	if (!abs_path)
		return (1);
	ft
	getcwd(NULL, 0));
	*/
}
