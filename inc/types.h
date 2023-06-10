/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:42:22 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/02 02:36:55 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_env
{
	char			*key;
	char			*value;
	int				*size;
	struct s_env	*next;
}						t_env;

typedef struct s_token
{
	int					tkn;
	char				*word;
	struct s_token		*next;
}						t_token;

typedef struct s_sentence
{
	char				**args;
	int					fd_i;
	int					fd_o;
	int					reds_inside;
	struct s_sentence	*previous;
	struct s_sentence	*next;
}						t_sentence;

/* typedef struct s_shell
 *
 * TODO:
 * - Incluir:
 * 	t_env			**lst_env;
 * 	t_sentence		*lst_sentence;
 *
 * */

typedef struct s_shell
{
	char				*line;
	t_env				*lst_env;
	t_token				*lst_token;
	int					sentence_count;
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

/* FREE_TAB  */
void		freetab(void **ptr);
void		free_array(char **tab);

/* T_ENV */
void		protect_malloc(void *arg);
t_env		*new_env(char *key, char *value);
t_env		*addfront_env(t_env *env, char *key, char *value);
void		envdel_one(t_env *node);
void		clear_env(t_env **env);
void		set_envsize(t_env *env);
t_env		*env_unlink(t_env **lst, t_env *to_remove);

/* T_SENTENCE  */
t_sentence	*new_sentence(char **args);
t_sentence	*find_last_sentence(t_sentence *lst);
void		addback_sentence(t_sentence **lst, t_sentence *new);
void		clear_sentence(t_sentence **lst);

/* T_STRING */
t_string	*ft_strnew(char *str, size_t length);
void		ft_stradd_front(t_string **lst, t_string *new);
void		ft_strsetlast(t_string *lst, t_string *laststr);
void		ft_stradd_back(t_string **lst, t_string *new);
void		ft_strdelone(t_string *lst, void (*del)(void *));
void		ft_strclear(t_string **lst, void (*del)(void *));
int			ft_strsize(t_string *lst);
size_t		ft_strtotallen(t_string *lst);
char		*ft_lst_to_str(t_string *lst);

#endif
