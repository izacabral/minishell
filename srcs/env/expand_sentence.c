#include "env.h"
#include "types.h"

char	*expand_sentence(char **sentence, t_env *env)
{
	char		*new;
	char		*old;
	t_string	*tmp;

	old = *sentence;
	tmp = scan_sentence(old, env);
	new = ft_lst_to_str(tmp);
	ft_strclear(&tmp, free);
	free(old);
	return (new);
}
