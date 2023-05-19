/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:18:43 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/19 09:18:48 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freetab(void **ptr)
{
	char	**tmp;
	int		i;

	if (!ptr)
		return ;
	i = 0;
	tmp = (char **)ptr;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(ptr);
}
