/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:45:45 by izsoares          #+#    #+#             */
/*   Updated: 2022/05/26 11:48:59 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	filled;

	filled = count * size;
	ptr = malloc (filled);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, filled);
	return (ptr);
}
