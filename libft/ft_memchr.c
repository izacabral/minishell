/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:56:41 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/14 21:03:03 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*bcpy;

	bcpy = (unsigned char *) b;
	index = 0;
	while (index < len)
	{
		if (bcpy[index] == (unsigned char) c)
			return ((unsigned char *) &bcpy[index]);
		index++;
	}
	return (NULL);
}
