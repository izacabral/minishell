/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:41:13 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/06 13:27:22 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "defines.h"
# include "types.h"
# include "env.h"
# include "exec.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

extern int	g_global;

// srcs/prompt/
void		init_shell(t_shell *data, char *envp[]);
void		launch_prog(t_shell *data);
void		int_handler(int signum);
char		*readline_gets(char *line);
void		setup_signals(void);

// srcs/parser/
int			isquotes(char c);
int			isdelim(char c);
t_tkn		which_delim(char *delim);
int			scan_line(t_token **lst, char *line);
int			lexer(t_token *lst);

// srcs/env/
t_env		*get_env(char *environ[]);
void		expandvars(char **sentences, t_env *env);
t_string	*path_to_lst(char *path);
int			check_varname(char *key);

// srcs/exec/
int			call_execve(char **args, char *path);
char		*prefix_slash(char **str);

// srcs/sentence/
void		create_sentences(t_env *env, t_token **lst_token, \
				t_sentence **lst_sentence);
int			new_index(char *str, int i);
int			no_quote_size(char *str);
int			quote_size(char *str, char quote);
char		*quotes_removed(char *str, int i, char *new_str);
void		remove_quotes(char **sentences);
char		**tkn_to_sentence(t_token **lst_token);
char		*while_no_quotes(char *str, int i, char *new_str);

// srcs/builtins/
int			check_export(char *key, char *str);
int			check_unset(char *key);
t_env		*compare_key(t_env *env, char *key);
int			export_builtins(int size, char *str[], t_shell *data);
void		export_error(char *str);
void		print_env(t_env *env);
void		print_export(t_env *env);
int			unset_builtins(int size, char *str[], t_shell *data);
int			ft_echo(char **arg);
int			ft_exit(int n);
int			pwd(void);

#endif
