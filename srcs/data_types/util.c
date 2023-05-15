#include "minishell.h"

/*Não quis mexer na libft da Iza, então coloquei aqui a minha função ft_strcmp*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			break;
		index++;
	}
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}