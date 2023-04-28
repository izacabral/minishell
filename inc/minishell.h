#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
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

// srcs/parser/
int		get_cmd(t_data **data, char *line);
void	parser_line(t_data **data, char *line);

#endif
