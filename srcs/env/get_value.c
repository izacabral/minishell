#include "env.h"
#include "libft.h"

static char	*set_format(char *, int size);
static char	*search_value(char *key, int size, t_env *env);

char	*get_value(char *var, int size, t_env *env)
{
	char	*value;
	char	*key;

	key = set_format(var, size + 1);
	value = search_value(key, size + 2, env);
	free(key);
	key = NULL;
	return (value);
}

static char	*set_format(char *var_name, int size)
{
	char	*output;

	output = malloc((size + 1) * sizeof(*output));
	if (!output)
	{
		ft_putstr_fd("Malloc error on set_format()\n", 2);
		return (NULL);
	}
	output[size] = '\0';
	output[size - 1] = '=';
	ft_memcpy(output, var_name, size - 1);
	return (output);
}

static char	*search_value(char *key, int size, t_env *env)
{
	while (env)
	{
		if (!ft_strncmp(key, env->key, size))
		{
			if (!env->value)
				return (NULL);
			return (ft_strdup(env->value));
		}
		env = env->next;
	}
	return (NULL);
}
