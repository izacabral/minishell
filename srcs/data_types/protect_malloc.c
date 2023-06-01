/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:49:22 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/31 22:49:24 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:void *arg - argument can be of any type
 * Scope			:checks whether dynamic memory allocation has occurred
 * Output			:none
 * 					:or
 * 					:error and exit
 */
void	protect_malloc(void *arg)
{
	if (arg == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(errno);
	}
}

