/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandvars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:29:34 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/14 16:29:36 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: expandvars(char **sentences, t_env *env)
 * Scope	: lê uma sentença e aplica expansões
 * Input	: char ** - sentença guardada em t_sentence
 *			: t_env * - lista com as variáveis de ambiente
 * Output	: void
 * Errors	: não se aplica
 *			: devolve a sentença com as expansões feitas (aspas não são eliminadas), caso não haja expansão, não faz nada
 * Uses		: [WIP] a ser integrado após ter a estrutura t_sentence definida. Posso modificar depois para receber t_sentence* em vez de char**
 */
void	expandvars(char **sentences, t_env *env)
{
	int	i;

	i = 0;
	while (sentences[i])
	{
		sentences[i] = expand_sentence(&sentences[i], env);
		i++;
	}
}
