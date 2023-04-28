/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:05:44 by izsoares          #+#    #+#             */
/*   Updated: 2022/06/14 21:07:41 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/* 
#include <stdio.h>
void	printlst(t_list *node)
{
	while(node)
	{
		printf("%s\n",(char *) node ->content);
		node = node -> next;
	}
}

int main(void)
{
	t_list *people;
	char *content1;
	char *content2;
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	people = ft_lstnew(content1);
	ft_lstadd_front(&people, ft_lstnew(content2));
	printlst(people);
	return (0);
}
 */