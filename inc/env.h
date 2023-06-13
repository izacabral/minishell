/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daolivei <daolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:03:44 by daolivei          #+#    #+#             */
/*   Updated: 2023/06/12 21:34:30 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	get_entry(char **key, char **value, char *var, int len);

// Var expansion
char		*expand_sentence(char **sentence, t_env *env);
t_string	*scan_sentence(char *sentence, t_env *env);
char		*get_value(char *var, int size, t_env *env);
t_quotes	which_quotes(char c);

#endif
