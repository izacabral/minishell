/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:11:46 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/10 17:38:21 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
	return ;
}

/* #include <stdlib.h>
#include <stdio.h>

void    ft_toupper_iteri(unsigned int i, char* c)
{
    (void) i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
	
	char str_ft_striteri[] = "eu quero ser maiuscula";
	ft_striteri(str_ft_striteri, ft_toupper_iteri);
	printf("%s\n", str_ft_striteri);
}
 */