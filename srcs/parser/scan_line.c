/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:15:02 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/21 02:19:54 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	token_lenght(char *token);
static int	token_lenght_quotes(char *token, char quote);

static int	add_token(t_token **lst, char *str, int lenght)
{
	char	*value;
	t_tkn	token;

	if (lenght < 0)
		return (lenght);
	if (!lenght)
		return (-1);
	value = malloc((lenght + 1) * sizeof(*value));
	if (!value)
		return (-1);
	ft_memcpy(value, str, lenght);
	value[lenght] = '\0';
	token = WORD;
	if (isdelim(*value))
		token = which_delim(value);
	addback_token(lst, new_token(value, token));
	return (lenght);
}

// return(2) -> É >> ou << ; reuturn(1); -> é > ou <
static int	delim_lenght(char *delim, char d)
{
	if (d == '|')
		return (1);
	if (*(delim + 1) == d)
		return (2);
	return (1);
}

// Bloco começa com aspas (simples ou duplas)
static int	token_lenght_quotes(char *token, char quote)
{
	int	len;
	int	error;

	len = 1;
	while (token[len] && token[len] != quote)
		len++;
	if (!token[len])
		return (-2);
	if (!ft_isspace(token[len + 1]) || !isdelim(token[len + 1]))
	{
		error = token_lenght(&token[len + 1]);
		if (error < 0)
			return (error);
		len += error;
	}
	return (len + 1);
}

// Bloco não começa com aspas - É palavra ou delimitador
static int	token_lenght(char *token)
{
	int	len;
	int	error;

	if (isdelim(*token))
		return (delim_lenght(token, *token));
	len = 0;
	while (token[len] && !ft_isspace(token[len]))
	{
		if (isquotes(token[len]))
		{
			error = token_lenght_quotes(&token[len], token[len]);
			if (error < 0)
				return (error);
			len += error;
		}
		else
			len++;
		if (isdelim(token[len]))
			break ;
	}
	return (len);
}

/*
 * Fn		: scan_line(t_token **lst, char * line)
 * Scope	: divide linha de comando em tokens palavra ou delimitadores
 * Input	: t_token **lst - endereço da lista de tokens
 *			: char * - linha de comando (retorno da readline())
 * Output	: int (0) - nenhum erro encontrado
 * Errors	: int (-1) - lst_token não pôde ser alocada
 *			: int (-2) - erro de sintaxe (aspas de fechamento não encontradas)
 * Uses		: launch_prog()
 */
int	scan_line(t_token **lst, char *line)
{
	char	*start;
	int		i;

	start = line;
	while (*start)
	{
		while (*start && ft_isspace(*start))
			start++;
		if (isquotes(*start))
			i = token_lenght_quotes(start, *start);
		else
			i = token_lenght(start);
		i = add_token(lst, start, i);
		if (i >= 0 && !*lst)
			i = -1;
		if (i < 0)
			return (i);
		start += i;
	}
	return (0);
}
