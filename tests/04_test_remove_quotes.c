/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:45:24 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/17 15:56:24 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int ver = 0; // verificação de retorno do teste

	/* CRIAÇÃO DO ARRAY DE STRINGS PARA TESTE */
	char *buffer[10];

	int i = 0;
	while (i < 10)
	{
		buffer[i] = NULL;
		i++;
	}
	buffer[0] = ft_strdup("\"teste\"");
	buffer[1] = ft_strdup("\"\"\"teste\"\"\"");
	buffer[2] = ft_strdup("\"\'teste\'\"");
	buffer[3] = ft_strdup("\'\'teste\'\'");
	buffer[4] = ft_strdup("--iza\' \'iza--");

	/* REMOÇÃO DAS ASPAS */
	remove_quotes(buffer);

	/* CRIAÇÃO DO ARRAY DE STRINGS COMO DEVERIAM FICAR */
	char *check[10];

	i = 0;
	while (i < 10)
	{
		check[i] = NULL;
		i++;
	}
	check[0] = "teste";
	check[1] = "teste";
	check[2] = "\'teste\'";
	check[3] = "teste";
	check[4] = "--iza iza--";

	/* COMPARA  BUFFER COM OS CHECKS ESPERADOS */
	i = 0;
	while (buffer[i])
	{
		ver = ft_strncmp(check[i], buffer[i], (ft_strlen(check[i]) + 1));
		if (ver != 0)
		{
			ver = i + 1;
			break;
		}
		i++;
	}

	/* LIBERAÇÃO DE BUFFER */
	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}

	if (ver == 0)
		ft_printf("Remove_quotes functions is ok\n");
	else
		ft_printf("Something is wrong with remove_quotes function\n");

	return (ver);
}




