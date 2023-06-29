/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:48:20 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/29 13:16:51 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	clear_env_dup(char **env_dup)
{
	int i;

	i = 0;
    if (!env_dup)
        return (1);
    while (env_dup[i])
	{
		free(env_dup[i]);
		i++;
	}
	free(env_dup[i]);
	free(env_dup);
	env_dup = NULL;
	return (0);
}