#include "minishell.h"
#include "env.h"

void	expandvars(char **sentences, t_env *env)
{
	int	i;

	i = 0;
	while (sentences[i])
	{
		sentences[i] = expand_sentence(&sentences[i], env);
		i++;
	}
}
