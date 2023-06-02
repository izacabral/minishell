/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:54:03 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/02 02:54:05 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_first(t_env **lst, t_env *to_remove);
static void	remove_last(t_env **lst, t_env *to_remove);
static void	remove_middle(t_env **lst, t_env *to_remove);

t_env	*env_unlink(t_env **lst, t_env *to_remove)
{
	t_env	*tmp;

	tmp = *lst;
	while (tmp && tmp != to_remove)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	if (tmp == *lst)
		remove_first(lst, to_remove);
	else if (!tmp->next)
		remove_last(lst, to_remove);
	else
		remove_middle(lst, to_remove);
	*(*lst)->size -= 1;
	return (to_remove);
}

static void	remove_first(t_env **lst, t_env *to_remove)
{
	*lst = (*lst)->next;
	to_remove->next = NULL;
	to_remove->size = NULL;
}

static void	remove_last(t_env **lst, t_env *to_remove)
{
	t_env	*previous;

	previous = *lst;
	while (previous->next != to_remove)
		previous = previous->next;
	previous->next = to_remove->next;
	to_remove->next = NULL;
	to_remove->size = NULL;
}

static void	remove_middle(t_env **lst, t_env *to_remove)
{
	t_env	*previous;

	previous = *lst;
	while (previous->next != to_remove)
		previous = previous->next;
	previous->next = to_remove->next;
	to_remove->next = NULL;
	to_remove->size = NULL;
}
