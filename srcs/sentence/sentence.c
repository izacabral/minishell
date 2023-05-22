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

t_token    *get_token_word(t_token **lst_token)
{
    t_token *tmp;

    tmp = *lst_token;
    if (!tmp)
        return (NULL);
    while (tmp->next && tmp->tkn != WORD)
        tmp = tmp->next;
    if (tmp->tkn != WORD)
        return (NULL);
    return (tmp);
}

size_t count_tkn_words(t_token **lst_token)
{
    size_t count;
    t_token *tmp;

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

char **tkn_to_sentence(t_token **lst_token)
{
    t_token *tmp;
    size_t  size;
    char    **args;
    size_t  i;

    tmp = get_token_word(&(*lst_token));
    size = count_tkn_words(&tmp);
    args = malloc(sizeof(char*) * (size + 1));
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