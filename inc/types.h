/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:42:22 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/19 09:18:11 by bda-silv         ###   ########.fr       */
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

//s_env | t_env

typedef struct s_token
{
	int					tkn;
	char				*word;
	struct s_token		*next;
}						t_token;

typedef struct s_sentence
{
	char 				**args;
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

#endif
