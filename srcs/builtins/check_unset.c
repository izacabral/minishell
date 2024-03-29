/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:49:36 by vchastin          #+#    #+#             */
/*   Updated: 2023/05/23 08:49:38 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:char *str - environment variable in wrong format
 * Output			:print the error on the screen
 */
static void	unset_error(char *str)
{
	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	ft_putstr_fd("`", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

/*
 * Input			:char *key - environment variable key
 * Scope			:checks that the key is in the correct format
 * Output			:-1 error
 *					: 1 sucess
 */
int	check_unset(char *key)
{
	int	i;
	int	code;

	i = -1;
	code = SUCESS_BUILTINS;
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			unset_error(key);
			code = ERROR_BUILTINS;
		}
	}
	return (code);
}
