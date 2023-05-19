#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "defines.h"
# include "types.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

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

// srcs/builtins/
int		ft_echo(char **arg);
int		ft_exit(int n);

#endif
