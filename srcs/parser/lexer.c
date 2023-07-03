/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:26:25 by izsoares          #+#    #+#             */
/*   Updated: 2023/07/03 20:13:06 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: print_syntax_error(char *word)
 * Scope	: print error message from lexer function
 * Input	: char *word da t_token (lista de tokens)
 *
 * Output	: error message
 * Errors	:
 *
 * Uses		: lexer()
 *
 * OBS		: assign error 258 to global variable representing ?
 */
static void	print_syntax_error(char *word, t_token *lst)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(word, 2);
	ft_putendl_fd("'", 2);
	has_hdoc(lst);
	if (g_global != 130)
		g_global = 2;
}

/*
 * Fn		: next_token(t_token *tmp)
 * Scope	: Validate token after a redirect token
 * 				Return correspondent error
 * Input	: t_token *tmp (lista de tokens)
 *
 * Output	: int (0) - no error found
 * Errors	: int (-1) - invalid token
 * Uses		: lexer_iterate()
 */
static int	next_token(t_token *tmp)
{
	if (!tmp->next)
	{
		print_syntax_error("newline", tmp);
		return (-1);
	}
	if (tmp->next && tmp->next->tkn != WORD)
	{
		print_syntax_error(tmp->next->word, tmp);
		return (-1);
	}
	else
		return (0);
}

/*
 * Fn		: lexer_iterate(t_token *tmp)
 * Scope	: Validate syntax in a t_token list
 * Input	: t_token *tmp (token list)
 *
 * Output	: int (0) - no error found
 * Errors	: int (-2) - syntax error
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
				print_syntax_error(tmp->next->word, tmp);
				return (-2);
			}
			else
				tmp = tmp->next;
		}
		if ((tmp->tkn >= PIPE))
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
 * Scope	: Validate syntax in a token list
 * Input	: t_token *tmp (token list)
 *
 * Output	: int (0) - no error found
 * Errors	: int (-1) - token list is empty
 *			: int (-2) - syntax error
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
		print_syntax_error(tmp->word, tmp);
		return (-2);
	}
	if (!tmp->next && (tmp->tkn >= IN))
	{
		print_syntax_error("newline", tmp);
		return (-2);
	}
	if (lexer_iterate(tmp) == -2)
		return (-2);
	return (0);
}
