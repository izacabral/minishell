#include "env.h"
#include "types.h"

/*
 * Fn		: expand_sentence(char **sentence, t_env *env)
 * Scope	: lê uma string e aplica expansões
 *			: a string antiga, se foi feita a expansão, é liberada
 * Input	: char ** - endereço de uma string
 *			: t_env * - lista com as variáveis de ambiente
 * Output	: char * - uma nova string alocada com as expansões aplicadas;
 *			:		 - a string sem modificações, caso nenhuma expansão encontrada
 * Errors	: não se aplica
 * Uses		: expandvars()
 */
char	*expand_sentence(char **sentence, t_env *env)
{
	char		*new;
	char		*old;
	t_string	*tmp;

	old = *sentence;
	tmp = scan_sentence(old, env);
	if (!tmp)
		return (old);
	new = ft_lst_to_str(tmp);
	ft_strclear(&tmp, free);
	free(old);
	return (new);
}
