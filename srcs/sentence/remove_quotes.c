/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:08:15 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/21 20:08:18 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: quote_size(char *str)
 * Scope	: loop through the string to find where the first quote is found
 *
 * Input	: char *str
 *
 * Output	: the index of the first quote ou 0 if no quotes
 * Errors	: not applicable
 *
 * Uses		: get_quote(char *str)
 */
static int	quote_size(char *str)
{
	int	len;
	int	size;

	len = 0;
	size = ft_strlen(str);
	while (str[len])
	{
		if (which_quotes(str[len]) != NONE && str[len + 1])
		{
			len++;
			break ;
		}
		len++;
	}
	if (len == size)
		len = 0;
	return (len);
}

/*
 * Fn		: get_quote(char *str)
 * Scope	: gets the type of quote
 *
 * Input	: char *str
 *
 * Output	: the caracter with type of quote or (null)
 * Errors	: not applicable
 *
 * Uses		: rem_str_quotes(char **str, int str_len)
 */
static char	get_quote(char *str)
{
	char	quote;
	int		i;
	int		q_len;

	quote = '\0';
	i = 0;
	q_len = quote_size(str);
	if (q_len == 0)
		return (quote);
	quote = str[q_len - 1];
	return (quote);
}

/*
 * Fn		: count_quotes(char *str)
 * Scope	: if has a type of quote, loop through the string counting it
 *
 * Input	: char *str
 *
 * Output	: 0 if no quotes or how many times the firt type of quotes occurs
 * Errors	: not applicable
 *
 * Uses		: rem_str_quotes(char **str, int str_len)
 */
static int	count_quotes(char *str)
{
	char	quote;
	int		count;
	int		i;

	quote = get_quote(str);
	count = 0;
	i = 0;
	if (quote == '\0')
		return (count);
	while (str[i])
	{
		if (str[i] == quote)
			count++;
		i++;
	}
	return (count);
}

/*
 * Fn		: rem_str_quotes(char **str, int str_len)
 * Scope	: iterate through the array of strings copying the strings
 *				 without the quotes and releasing the old strings
 *
 * Input	: char **str, int str_len
 *
 * Output	: new array of strings without quotes
 * Errors	: not applicable
 *
 * Uses		: remove_quotes(char **str)
 */
static char	*rem_str_quotes(char **str, int str_len)
{
	int		i;
	char	quote;
	int		n_size;
	char	*new_str;

	i = 0;
	quote = get_quote(*str);
	n_size = str_len - count_quotes(*str);
	new_str = malloc (sizeof(char) * (n_size + 1));
	if (!new_str)
		return (NULL);
	n_size = 0;
	while (str[0][i])
	{
		if (str[0][i] != quote)
			new_str[n_size++] = str[0][i];
		i++;
	}
	new_str[n_size] = '\0';
	free(*str);
	return (new_str);
}

/*
 * Fn		: remove_quotes(char **str)
 * Scope	: iterate through the array of strings applying the
 *				rem_str_quotes function
 *
 * Input	: char **str
 *
 * Output	: void
 * Errors	: not applicable
 *
 * Uses		: create_sentences(t_env *env, t_token **lst_token,
 *				t_sentence **lst_sentence)
 */
void	remove_quotes(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = rem_str_quotes(&str[i], ft_strlen(str[i]));
		i++;
	}
}
