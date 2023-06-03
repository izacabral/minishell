/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:01:33 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/03 15:59:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	heredoc(char *str, int fd_out)
{
	char	*read;

	read = NULL;
	while (1)
	{
		read = readline(">");
		if (!read)
			return (0);
		if (ft_strncmp(read, str, ft_strlen(str)) == 0)
			break ;
		ft_putendl_fd(read, fd_out);
		free(read);
	}
	free(read);
	return (0);
}
