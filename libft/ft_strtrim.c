/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:36:21 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/12 19:26:10 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	end;
	size_t	length;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
	{
		end--;
	}
	length = end - start;
	trimed = ft_substr(s1, start, length);
	return (trimed);
}
