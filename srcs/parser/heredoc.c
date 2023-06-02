/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:01:33 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/02 00:01:52 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc(char *str)
{
	char	*read;
	char	*word;

	word = NULL;
	read = NULL;
	while (1)
	{
		read = readline(">");
		if (ft_strncmp(read, str, ft_strlen(str)) == 0)
			break ;
		if (!word)
		{
			word = malloc(1);
			word[0] = '\0';
		}
		word = ft_strjoin_free(word, read);
		free(read);
	}
	free(read);
	return (word);
}
