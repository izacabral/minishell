/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:41:13 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/14 20:43:49 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "defines.h"
# include "types.h"
# include "env.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int	g_global;

// srcs/prompt/
void	setup_signals(void);
void	int_handler(int signum);
char	*rl_gets(char *line);
void	launch_prog(t_shell *data);

// srcs/parser/
int		isquotes(char c);
int		isdelim(char c);
t_tkn	which_delim(char *delim);
int		scan_line(t_token **lst, char *line);
int		lexer(t_token *lst);

//srcs/env/
void	expandvars(char **sentences, t_env *env);

#endif
