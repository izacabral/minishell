/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:18:51 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/05 16:42:43 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_shell(t_shell *data)
{
	data->sentence_count = size_sentence(data->lst_sentence);
	data->pipe_count = counting_pipes(data->lst_token);
	data->redirect_count = counting_redirects(data->lst_token);
	if (data->pipe_count > 0)
	{
		data->pipes = malloc (sizeof(int) * data->pipe_count);
		if (!data->pipes)
		{
			ft_printf("Malloc error array pipes\n");
		}
	}
	if (data->redirect_count > 0)
	{
		data->reds = malloc (sizeof(int) * data->redirect_count);
		if (!data->reds)
		{
			ft_printf("Malloc error array reds\n");
		}
	}
}
