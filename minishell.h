#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "defines.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

void	setup_signals(void);
void	int_handler(int signum);
char	*rl_gets(char *line);
char	*get_cmd(char *buffer, char *line);

#endif
