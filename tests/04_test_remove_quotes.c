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
	char *buffer[11];

	int i = 0;
	while (i < 11)
	{
		buffer[i] = NULL;
		i++;
	}
	buffer[0] = ft_strdup("\"teste\"");
	buffer[1] = ft_strdup("\"\"\"teste\"\"\"");
	buffer[2] = ft_strdup("\"\'teste\'\"");
	buffer[3] = ft_strdup("\'\'teste\'\'");
	buffer[4] = ft_strdup("--iza\' \'iza--");
	buffer[5] = ft_strdup("\" \' teste \' \'teste\' \"");
	buffer[6] = ft_strdup("\"teste\"--iza--");
	buffer[7] = ft_strdup("teste\"--iza--\"");
	buffer[8] = ft_strdup("\"teste\"--iza--\"teste\"--iza--\'teste\'");
	buffer[9] = ft_strdup("\"um\"dois\'três\'");

	/* REMOÇÃO DAS ASPAS */
	remove_quotes(buffer);

	/* CRIAÇÃO DO ARRAY DE STRINGS COMO DEVERIAM FICAR */
	char *check[11];

	i = 0;
	while (i < 11)
	{
		check[i] = NULL;
		i++;
	}
	check[0] = "teste";
	check[1] = "teste";
	check[2] = "\'teste\'";
	check[3] = "teste";
	check[4] = "--iza iza--";
	check[5] = " \' teste \' \'teste\' ";
	check[6] = "teste--iza--";
	check[7] = "teste--iza--";
	check[8] = "teste--iza--teste--iza--teste";
	check[9] = "umdoistrês";

	/* COMPARA  BUFFER COM OS CHECKS ESPERADOS */
	i = 0;
	while (buffer[i])
	{
		ver = ft_strncmp(check[i], buffer[i], (ft_strlen(check[i]) + 1));
		ft_printf("buffer[%d]:%s\n", i, buffer[i]);
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
		ft_printf("Something is wrong with remove_quotes function, ver= %d\n", ver);

	return (ver);
}




