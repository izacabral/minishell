/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:04:59 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/15 11:39:53 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	char	*s2;
	size_t	s1len;
	size_t	index;

	if (!s1)
		return (NULL);
	s1cpy = (char *)s1;
	s1len = ft_strlen(s1cpy);
	s2 = malloc((s1len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	index = 0;
	while (index < s1len)
	{
		s2[index] = s1cpy[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}
