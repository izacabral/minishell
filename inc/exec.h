/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:39:49 by daolivei          #+#    #+#             */
/*   Updated: 2023/05/22 17:21:21 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "types.h"

int			call_execve(char **args, t_string *path);
int		launch_command(char **args);
int		call_builtin(char **args, t_shell *data, t_builtin builtin);

#endif
