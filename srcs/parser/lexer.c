/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:26:25 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/17 13:55:48 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: print_syntax_error(char *word)
 * Scope	: printa a mensagem de error da função lexer
 * Input	: char *word da t_token (lista de tokens)
 *
 * Output	: mensagem de error
 * Errors	:
 *
 * Uses		: lexer()
 *
 * OBS		: setar o erro 258 para a variável global que representará o ?
 */
static void	print_syntax_error(char *word)
{
	ft_printf("minishell: syntax error near unexpected token '%s'\n", word);
	g_global = 258;
}

/*
 * Fn		: next_token(t_token *tmp)
 * Scope	: Valida o próximo token depois de um token de redirec.
 * 				E retorna a msg de erro correspondente.
 * Input	: t_token *tmp (lista de tokens)
 *
 * Output	: int (0) - nenhum erro encontrado
 * Errors	: int (-1) - token invalido
 * Uses		: lexer_iterate()
 */
static int	next_token(t_token *tmp)
{
	if (!tmp->next)
	{
		print_syntax_error("newline");
		return (-1);
	}
	if (tmp->next && tmp->next->tkn != WORD)
	{
		print_syntax_error(tmp->next->word);
		return (-1);
	}
	else
		return (0);
}

/*
 * Fn		: lexer_iterate(t_token *tmp)
 * Scope	: percorrer a t_token *tmp validando a sintaxe. Função criada
 * 				para diminuir a quantidade de linhas da lexer
 * Input	: t_token *tmp (lista de tokens)
 *
 * Output	: int (0) - nenhum erro encontrado
 * Errors	: int (-2) - erro de sintaxe
 * Uses		: lexer()
 */
static int	lexer_iterate(t_token *tmp)
{
	while (tmp->next)
	{
		while (tmp->tkn == WORD && tmp->next)
			tmp = tmp->next;
		if (tmp->tkn == PIPE && tmp->next)
		{
			if (tmp->next->tkn == PIPE)
			{
				print_syntax_error(tmp->next->word);
				return (-2);
			}
			else
				tmp = tmp->next;
		}
		if ((tmp->tkn == IN || tmp->tkn == OUT
				|| tmp->tkn == HDOC || tmp->tkn == APPEND))
		{
			if (next_token(tmp) == -1)
				return (-2);
			else
				tmp = tmp->next;
		}
	}
	return (0);
}

/*
 * Fn		: lexer(t_token *lst)
 * Scope	: percorrer a t_token *tmp validando a sintaxe.
 * Input	: t_token *tmp (lista de tokens)
 *
 * Output	: int (0) - nenhum erro encontrado
 * Errors	: int (-1) - t_token *lst não existe
 *			: int (-2) - erro de sintaxe
 * Uses		: lexer()
 */
int	lexer(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	if (!tmp)
		return (-1);
	if (tmp->tkn == PIPE)
	{
		print_syntax_error(tmp->word);
		return (-2);
	}
	if (!tmp->next && (tmp->tkn == IN || tmp->tkn == OUT
			|| tmp->tkn == HDOC || tmp->tkn == APPEND))
	{
		print_syntax_error("newline");
		return (-2);
	}
	if (lexer_iterate(tmp) == -2)
		return (-2);
	return (0);
}
