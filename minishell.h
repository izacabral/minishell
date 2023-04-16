#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "defines.h"
# include "types.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

t_data	*new_data(t_token token, char **value);
void	data_addback(t_data **lst, t_data *new);
void	data_clear(t_data **lst, void (*del)(void **));
t_data	*data_find_last(t_data *lst);
void	freetab(void **ptr);
int		ft_isspace(int c);
void	setup_signals(void);
void	int_handler(int signum);
char	*rl_gets(char *line);
int		get_cmd(t_data **data, char *line);
void	parser_line(t_data **data, char *line);

#endif
