/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:43:33 by izsoares          #+#    #+#             */
/*   Updated: 2022/05/19 14:06:30 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	index;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	index = 0;
	if (size > 0 && size > dstlen)
	{
		while (src[index] && index < (size - dstlen - 1))
		{
			dst[dstlen + index] = src[index];
			index++;
		}
		dst[dstlen + index] = '\0';
		return (srclen + dstlen);
	}
	return (size + srclen);
}
