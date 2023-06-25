/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:55:57 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/14 13:56:07 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *data)
{
	if (data->line)
		free(data->line);
	if (data->lst_token)
		clear_token(&data->lst_token);
	if (data->lst_sentence)
		clear_sentence(&data->lst_sentence);
	if (data->pipes)
		clear_pipe(data);
	if (data->reds)
		free(data->reds);
	init_shell(data);
}
