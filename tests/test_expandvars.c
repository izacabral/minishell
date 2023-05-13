#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	main(void)
{
	t_env	*var1;
	t_env	*var2;
	char	**tab;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	var1 = malloc(sizeof(*var1));
	var2 = malloc(sizeof(*var2));
	if (!(var1 && var2))
		return (1);
	var1->key = ft_strdup("a=");
	var1->value = ft_strdup("var1");
	var2->key = ft_strdup("b=");
	var2->value = NULL;
	var1->next = var2;
	var2->next = NULL;
	tab = malloc(5 * sizeof(*tab));
	str1 = ft_strdup("Test variable $a for expansion\n");
	str2 = ft_strdup("Test $b for no value\n");
	str3 = ft_strdup("Test variable \"$a some word\" inside quotes\n");
	str4 = ft_strdup("Test \'$a\' no expansion\n");
	tab[0] = str1;
	tab[1] = str2;
	tab[2] = str3;
	tab[3] = str4;
	tab[4] = NULL;
	expandvars(tab, var1);
	free(var1->key);
	free(var1->value);
	free(var2->key);
	free(var2->value);
	free(var1);
	free(var2);
	ft_putstr_fd(tab[0], 1);
	ft_putstr_fd(tab[1], 1);
	ft_putstr_fd(tab[2], 1);
	ft_putstr_fd(tab[3], 1);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	free(tab);
	return (0);
}
