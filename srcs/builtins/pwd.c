/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:13:30 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/18 11:18:33 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*abs_path;

	abs_path = getcwd(NULL, 0) != NULL;
	if (!abs_path)
	{
		free(abs_path);
		abs_path = NULL;
		return (1);
	}
	else
	{
		printf("%s\n", abs_path);
		free(abs_path);
		abs_path = NULL;
	}
	return (0);
}
