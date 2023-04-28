/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:57:39 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/14 20:58:52 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	indexa;
	size_t	indexb;
	size_t	litlen;

	indexa = 0;
	indexb = 0;
	litlen = ft_strlen(little);
	if (little[indexb] == '\0')
		return ((char *)big);
	while (big[indexa] && len-- >= litlen)
	{
		while (big[indexa + indexb] == little[indexb] && big[indexa + indexb])
		{
			indexb++;
		}
		if (little[indexb] == '\0')
			return ((char *)big + indexa);
		indexa++;
		indexb = 0;
	}
	return (0);
}
