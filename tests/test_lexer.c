/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:45:24 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/13 11:33:59 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

//Função para testar o lexer

int	main(void)
{
	char	*buffer[25];
	int 	ret;
	t_token	*lst;
	int 	i;
	int 	ver;

	lst = NULL;
	ret = 0;
	i = 0;
	ver = 0;

	while (i < 25)
	{
		buffer[i] = NULL;
		i++;
	}

	buffer[0] = "cat teste > teste2";
	buffer[1] = "cat teste > teste2 | wc";
	buffer[2] = "cat teste | wc";
	buffer[3] = "cat teste | wc < teste2";
	buffer[4] = "cat teste2 < teste3 |ls | teste4 > clear";
	buffer[5] = "cat teste2 | < teste3";
	buffer[6] = "cat teste2 |< teste3";
	buffer[7] = "cat teste2 |";
	buffer[8] = "cat main.c |> teste";


	i = 0;

	while (buffer[i])
	{
		scan_line(&lst, buffer[i]);
		ret = lexer(lst);
		if (lst)
		{
			clear_token(&lst);
		}
		if (ret == 0)
		{
			lst = NULL;
			i++;
		}
		if (ret != 0)
		{
			ver = -1;
			break;
		}
	}

	i = 0;
	while (i < 25)
	{
		buffer[i] = NULL;
		i++;
	}

	buffer[0] = "| teste2";
	buffer[1] = "|teste2";
	buffer[2] = "< | teste3";
	buffer[3] = "<| teste3";
	buffer[4] = "cat teste2 <| teste3";
	buffer[5] = "cat teste2 < |";
	buffer[6] = "cat teste2 < | teste3";
	buffer[7] = "cat teste2 <";
	buffer[8] = "<< |";
	buffer[9] = "<<|";
	buffer[10] = "cat teste2 << | teste3";
	buffer[11] = "cat teste2 <<";
	buffer[12] = "cat teste2 >>| teste3";
	buffer[13] = "cat teste2 >>";
	buffer[14] = "cat teste2 > | teste3";
	buffer[15] = "cat teste2 > |";
	buffer[16] = "cat teste2 > ";
	buffer[17] = "<";
	buffer[18] = "<<";
	buffer[19] = ">>";
	buffer[20] = ">";


	i = 0;

	while (buffer[i])
	{
		scan_line(&lst, buffer[i]);
		ft_printf("buffer[%i]:  %s\n", i, buffer[i]);
		ret = lexer(lst);
		ft_printf("\n");
		if (lst)
		{
			clear_token(&lst);
		}
		if (ret == -2)
		{
			lst = NULL;
			i++;
		}
		if (ret != -2)
		{
			ver = -2;
			break;
		}
	}
	if (ver == 0)
		ft_printf ("\n\nlexer is ok\n");
	else
		ft_printf ("\n\nsomething is wrong ret =%i", ver);
	return (ver);
}

