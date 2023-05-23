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

t_token	*get_token_word(t_token **lst_token)
{
	if (!(*lst_token))
		return (NULL);
	while ((*lst_token)->next && (*lst_token)->tkn != WORD)
		*lst_token = (*lst_token)->next;
	if ((*lst_token)->tkn != WORD)
		return (NULL);
	return (*lst_token);
}

t_token	*get_not_word(t_token **lst_token)
{
	if (!(*lst_token))
		return (NULL);
	while ((*lst_token) && (*lst_token)->tkn == WORD)
		*lst_token = (*lst_token)->next;
	return (*lst_token);
}

size_t	count_tkn_words(t_token **lst_token)
{
	size_t	count;
	t_token	*tmp;

	count = 0;
	tmp = get_token_word(&(*lst_token));
	if (!(tmp))
		return (count);
	while (tmp && tmp->tkn == WORD)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char	**tkn_to_sentence(t_token **lst_token)
{
	t_token	*tmp;
	size_t	size;
	char	**args;
	size_t	i;

	tmp = get_token_word(&(*lst_token));
	size = count_tkn_words(&tmp);
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (NULL);
	args[size] = NULL;
	i = 0;
	while (i < size)
	{
		args[i] = ft_strdup(tmp->word);
		i++;
		tmp = tmp->next;
	}
	return (args);
}

int	quote_size(char *str)
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

char	get_quote(char *str)
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

int	count_quotes(char *str)
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

char	*rem_str_quotes(char **str, int str_len)
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
	str = NULL;
	return (new_str);
}

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

void create_sentences(t_env *env, t_token **lst_token, t_sentence **lst_sentence)
{
	char	**args;

	while (*lst_token)
	{
		args = tkn_to_sentence(&(*lst_token));
		expandvars(args, env);
		remove_quotes(args);
		addback_sentence(&(*lst_sentence), new_sentence(args));
		*lst_token = get_not_word(&(*lst_token));
	}
}

