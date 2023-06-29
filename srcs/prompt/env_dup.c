/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:09:36 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/28 14:55:27 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    env_dup(char *envp[], t_shell *data)
{
    int len;
    int i;

    len = -1;
    i = 0;
    if (!envp)
        return ;
    while (envp[++len])
        ;
    data->env_dup = malloc(sizeof(char *) * (len) + 1);
    if (!data->env_dup)
        return ;
    while (envp[i])
    {
        data->env_dup[i] = ft_strdup(envp[i]);
        i++;
    }
    data->env_dup[i] = NULL;
}