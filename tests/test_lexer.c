/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:45:24 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/11 17:45:30 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

//Função para testar o lexer

int	main(void)
{
	char	*buffer;
	int 	ret;
	t_token	*lst;

	buffer = NULL;
	lst = NULL;
	while (1)
	{
		buffer = readline("Press <Ctrl+D> to exit~ ");
		if (!buffer)
			break ;
		ret = scan_line(&lst, buffer);
		printf("scan_line return= %i\n", ret);
		ret = lexer(lst);
		printf("lexer return= %i\n", ret);
		if (lst)
		{
			print_data((void *)lst, TOKEN);
			clear_token(&lst);
		}
	}
	return (0);
}

