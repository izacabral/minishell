/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:01:33 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/06/14 22:50:22 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	isquoted(char *str);

int	heredoc(char **str, t_env *env, int fd_out)
{
	char	*read;
	char	expand;

	expand = isquoted(*str);
	if (expand)
		*str = remove_hdoc_quotes(*str);
	read = NULL;
	while (1)
	{
		read = readline(">");
		if (!read)
			return (0);
		if (ft_strncmp(read, *str, ft_strlen(*str)) == 0)
			break ;
		if (expand)
			expand_hdoc_var(str, env);
		ft_putendl_fd(read, fd_out);
		free(read);
	}
	free(read);
	return (0);
}

static int	isquoted(char *str)
{
	while (*str)
	{
		if (isquotes(*str))
			return (1);
		str++;
	}
	return (0);
}
