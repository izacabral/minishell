#include "minishell.h"

/*Faz uma cópia do envp. Lembrando que as variáveis de ambientes tem formato key=value
Seria uma boa criar new_env aqui e passar como argumento para add_env?
Usar ft_substr e uma função para achar o '=' ao inves de
ft_split pode ser uma boa caso ocorra problema no futuro.*/
t_env	*get_env(char *environ[])
{
	int		index;
	char	**dict_split;
	t_env	*env;

	index = 0;
	env = NULL;
	dict_split = NULL;
	while (environ[index])
	{
		dict_split = ft_split(environ[index], '=');
		env = add_env(env, dict_split[0], dict_split[1]);
		dict_split = NULL;
		index++;
	}
	env->size = index;
	return (env);
}
