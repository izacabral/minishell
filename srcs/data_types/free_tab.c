/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:18:43 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/23 08:57:28 by vchastin         ###   ########.fr       */
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

void	free_array(char **tab)
{
	size_t	i;
	char	*s;

	i = 0;
	while (tab[i])
	{
		s = tab[i];
		free(s);
		i++;
	}
	free(tab);
	tab = NULL;
}
