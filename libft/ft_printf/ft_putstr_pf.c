/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:14:42 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/30 12:53:25 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s)
{
	int	length;

	length = 0;
	if (!s)
	{
		length += write(1, "(null)", 6);
		return (length);
	}
	while (*s)
	{
		length += write (1, s++, 1);
	}
	return (length);
}
