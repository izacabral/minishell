/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:28:08 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/15 16:01:33 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
/*
 * cd = changes directory
 * brief: changes from the actual dir to the dir specified in path
 * and updates the env variables PWD and OLD_PDW
 * t_env *env: a pointer to a struct containing the PWD and OLD_PWD
 * vars
 * char *path: pointer to a string with a designed path
*/

int	cd(t_env *env, char *path)
{
	// PWD = getcwd(NULL, 0);
	chdir(path);
	// OLD_PWD = getcwd(NULL, 0);
	return (0);
}
