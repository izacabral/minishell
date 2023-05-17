#ifndef TYPES_H
# define TYPES_H

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

/*Por enquanto não senti necessidade de utilizar uma lista duplamente encadeada
Adicionei variavel 'size' para saber a quantidades de variaveis de ambientes que estão na lista*/
typedef struct s_env
{
	char			*key;
	char			*value;
	int				size;
	struct s_env	*next;
}						t_env;


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
	t_env				*lst_env;
	t_token				*lst_token;
	int					sentence_count;
	//t_sentence		*lst_sentence;
	int					pipe_count;
	int					redirect_count;
	int					*pipes;
	int					*reds;
}						t_shell;

/* T_TOKEN  */
t_token		*new_token(char *ptr, t_tkn t);
void		addback_token(t_token **lst, t_token *new);
t_token		*find_last_token(t_token *lst);
void		clear_token(t_token **lst);
// freetab() não está sendo usada, mas deixei caso seja necessária
void		freetab(void **ptr);
/*Function that duplicates the environment variable is in the path dataypes/get_env.c*/
t_env		*get_env(char *environ[]);
/*Function that give free in the env list is in the path dataypes/free_env.c*/
void		del_lst(t_env *env);
void		del_one(t_env *node);
/*Function to compare if the key that was passed as an argument is equal
to the key that is in the env list. Include in path dataypes/export_builtins.c*/
t_env		*compare_key(t_env *env, char *key);
/*Function that checks whether dynamic memory allocation has occurred*/
void		protect_malloc(void *arg);
/*Function that add key and value in a new node is in the path dataypes/print_export.c*/
t_env		*new_env(char *key, char *value, int size);
/*Function that prints environment variables in order is in the path dataypes/print_export.c*/
void		print_export(t_env *env);
/*Function that checks that the key is in the correct format is in the path dataypes/check_export.c*/
int			check_export(char *key, char *str);
/*Function that print the export error on the screen is in the path dataypes/check_export.c*/
void		export_error(char *str);
/*Function that free elements from array is in the path dataypes/free_tab.c*/
void		free_array(char **tab);
/*Function that print the envp list is in the path dataypes/env_builtin.c*/
void		print_env(t_env *env);
/*Function that manipulates the result of the command export. Include in path dataypes/export_builtins.c*/
int			export_builtins(int size, char *str[], t_shell data);
/**/
int			ft_strcmp(const char *s1, const char *s2);
/*Function that add keys and values to the node*/
t_env		*add_env(t_env *env, char *key, char *value);
/*Function that checks that the key is in the correct format is in the path dataypes/check_unset.c*/
int			check_unset(char *key);
#endif
