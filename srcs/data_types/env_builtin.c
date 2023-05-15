#include "minishell.h"

/*
 * Input			:t_env *env - envp list(head)
 * Output			:print environment variables(envp list)
 * 					:Example: PATH=/usr/local/bin
 */
void	print_env(t_env *env)
{
	t_env  *tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putchar_fd('\n', 1);
		}
		tmp = tmp->next;
	}
}

/*O envp exportado/duplicado deve sair no terminal
quando a nossa minishell estiver sendo executada.
Por isso, temos que ter uma outra função para converter
a lista(t_env) para o formato 'char **' novamente*/
/*static char	**env_list_to_array(t_env *env)
{
	char	**envp;
	int		i;
	t_env	*node;

	envp = malloc(sizeof(char *) * (env->size + 1));
	protect_malloc(envp);
	node = env;
	i = - 1;
	while(++i < env->size)
	{
		envp[i] = ft_strdup(node->key);
		envp[i] = ft_strjoin_free(envp[i], "=");
		envp[i] = ft_strjoin_free(envp[i], node->value);
		node = node->next;
	}
	envp[i] == NULL;
	return (envp);
}*/


