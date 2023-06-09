/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcalvell <gcalvell@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:05:10 by gcalvell          #+#    #+#             */
/*   Updated: 2023/06/08 19:05:10 by gcalvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	ft_strequal(char *src, char *cmp)
{
	int	i_src;
	int	i_cmp;

	i_src = 0;
	i_cmp = 0;
	while (src[i_src] != '\0' && cmp[i_cmp])
	{
		i_src++;
		i_cmp++;
	}
	if (src[i_src] != cmp[i_cmp])
		return (1);
	else
		return (0);
}
