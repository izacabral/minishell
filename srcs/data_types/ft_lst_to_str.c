/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:27:45 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/05 14:34:36 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_lst_to_str(t_string *lst)
{
	char	*str;
	size_t	length;
	int		i;

	length = ft_strtotallen(lst);
	if (!length)
		return (NULL);
	str = malloc((length + 1) * sizeof(*str));
	str[length] = '\0';
	i = 0;
	while (lst)
	{
		if (lst->content)
			ft_memcpy(&str[i], lst->content, lst->length);
		i += lst->length;
		lst = lst->next;
	}
	return (str);
}
