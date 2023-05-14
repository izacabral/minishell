#ifndef ENV_H
# define ENV_H
# include "types.h"

typedef enum e_quotes
{
	NONE,
	SINGLE,
	DOUBLE,
}	t_quotes;

typedef struct s_repl
{
	t_quotes	quote;
	char		*old;
	int			old_sz;
	char		*new;
	int			new_sz;
}	t_repl;

typedef struct s_string
{
	size_t			length;
	char			*content;
	struct s_string	*last;
	struct s_string	*next;
}					t_string;

// Var expansion
char		*expand_sentence(char **sentence, t_env *env);
t_string	*scan_sentence(char *sentence, t_env *env);
char		*get_value(char *var, int size, t_env *env);
t_quotes	which_quotes(char c);
// T_STRING
t_string	*ft_strnew(char *str, size_t length);
void		ft_stradd_front(t_string **lst, t_string *);
void		ft_strsetlast(t_string *lst, t_string *laststr);
void		ft_stradd_back(t_string **lst, t_string *new);
void		ft_strdelone(t_string *lst, void (*del)(void *));
void		ft_strclear(t_string **lst, void (*del)(void *));
int			ft_strsize(t_string *lst);
size_t		ft_strtotallen(t_string *lst);
char		*ft_lst_to_str(t_string *lst);

#endif
