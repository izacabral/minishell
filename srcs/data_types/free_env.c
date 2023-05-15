#include "minishell.h"

/*
 * Input			:t_env - envp list
 * Scope			:clear env list
 * Output			:none
 */
void	free_env(t_env *env)
{
	t_env	*node;

	while (env)
	{
		node = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = node;
	}
}
