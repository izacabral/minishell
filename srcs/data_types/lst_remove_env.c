#include "minishell.h"

void	del_one(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/*
 * Input			:t_env - envp list
 * Scope			:clear env list
 * Output			:none
 */
void	del_lst(t_env *env)
{
	t_env	*node;

	while (env)
	{
		node = env->next;
		del_one(env);
		env = node;
	}
}
