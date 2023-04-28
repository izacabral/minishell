/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:41:57 by izsoares          #+#    #+#             */
/*   Updated: 2022/05/21 20:09:34 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*memory_dest;
	const char	*memory_src;
	size_t		index;

	memory_dest = dest;
	memory_src = src;
	index = n;
	if (memory_src < memory_dest)
	{
		while (index)
		{
			index--;
			memory_dest[index] = memory_src[index];
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
