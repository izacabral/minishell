#ifndef TYPES_H
# define TYPES_H
# include <stdlib.h>

typedef enum e_tkn
{
	ERROR,
	WORD,
	PIPE,
	IN,
	OUT,
	HDOC,
	APPEND
}	t_tkn;

//s_env | t_env

typedef struct s_token
{
	int					tkn;
	char				*word;
	struct s_token		*next;
}						t_token;

// s_sentence | t_sentence

typedef struct s_shell
{
	char				*line;
	//t_env				**lst_env;
	t_token				*lst_token;
	int					sentence_count;
	//t_sentence		*lst_sentence;
	int					pipe_count;
	int					redirect_count;
	int					*pipes;
	int					*reds;
}						t_shell;

typedef struct s_string
{
	size_t			length;
	char			*content;
	struct s_string	*last;
	struct s_string	*next;
}					t_string;

/* T_TOKEN  */
t_token		*new_token(char *ptr, t_tkn t);
void		addback_token(t_token **lst, t_token *new);
t_token		*find_last_token(t_token *lst);
void		clear_token(t_token **lst);
// freetab() não está sendo usada, mas deixei caso seja necessária
void		freetab(void **ptr);
// T_STRING
t_string	*ft_strnew(char *str, size_t length);
void		ft_stradd_front(t_string **lst, t_string *);
void		ft_strsetlast(t_string *lst, t_string *laststr);
void		ft_stradd_back(t_string **lst, t_string *new);
void		ft_strdelone(t_string *lst, void (*del)(void *));
void		ft_strclear(t_string **lst, void (*del)(void *));
int			ft_strsize(t_string *lst);

#endif
