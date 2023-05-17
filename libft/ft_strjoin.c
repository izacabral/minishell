/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:43:42 by izsoares          #+#    #+#             */
/*   Updated: 2023/02/19 18:19:49 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		indexa;
	int		indexb;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	newstr = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	indexa = 0;
	indexb = 0;
	while (s1[indexa])
	{
		newstr[indexa] = s1[indexa];
		indexa++;
	}
	while (s2[indexb])
		newstr[indexa++] = s2[indexb++];
	newstr[indexa] = '\0';
	return (newstr);
}
