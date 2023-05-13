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
	tab = malloc(3 * sizeof(*tab));
	str1 = ft_strdup("Test variable $a for expansion\n");
	str2 = ft_strdup("Test $b for no value\n");
	tab[0] = str1;
	tab[1] = str2;
	tab[2] = NULL;
	expandvars(tab, var1);
	ft_putstr_fd(tab[0], 1);
	ft_putstr_fd(tab[1], 1);
	return (0);
}
