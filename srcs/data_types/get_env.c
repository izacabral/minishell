#include "minishell.h"

/*
 * Input			:none
 * Output			:list allocated in memory
 * 					:or
 * 					:error and exit
 */
static t_env	*create_env(void)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	protect_malloc(node);
	return (node);
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - environment variable key
 *					:char *value - environment variable kvalue
 * Scope			:creating a new node
 * Output			:add keys and values to the node
 */
static t_env	*add_env(t_env *env, char *key, char *value)
{
	t_env	*new_env;

	new_env = create_env();
	new_env->key = key;
	new_env->value = ft_strtrim(value, "'");
	if (env == NULL)
	{
		env = new_env;
		new_env->next = NULL;
	}
	else
	{
		new_env->next = env;
		env = new_env;
	}
	return (env);
}

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
