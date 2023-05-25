/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:42:22 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/23 11:04:41 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* T_TOKEN  */
t_token		*new_token(char *ptr, t_tkn t);
void		addback_token(t_token **lst, t_token *new);
t_token		*find_last_token(t_token *lst);
void		clear_token(t_token **lst);
// freetab() não está sendo usada, mas deixei caso seja necessária
void		freetab(void **ptr);
t_env		*get_env(char *environ[]);
void		del_lst(t_env *env);
void		del_one(t_env *node);
t_env		*compare_key(t_env *env, char *key);
/*Function that checks whether dynamic memory allocation has occurred*/
void		protect_malloc(void *arg);
t_env		*new_env(char *key, char *value, int size);
void		print_export(t_env *env);
int			check_export(char *key, char *str);
void		export_error(char *str);
void		free_array(char **tab);
void		print_env(t_env *env);
int			export_builtins(int size, char *str[], t_shell data);
int			unset_builtins(int size, char *str[], t_shell data);
t_env		*add_env(t_env *env, char *key, char *value);
int			check_unset(char *key);
#endif
