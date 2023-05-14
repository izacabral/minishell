#include "minishell.h"

/*
 * Teste para a função de expansão de variáveis
 * Compilar com a libft e os arquivos:
 * tests/test_expandvars.c srcs/env/expand_sentence.c srcs/env/expandvars.c srcs/env/get_value.c srcs/env/scan_sentence.c srcs/env/which_quotes.c srcs/env/ft_strnew.c srcs/env/ft_stradd_back.c srcs/env/ft_strsize.c srcs/env/ft_strsetlast.c srcs/env/ft_lst_to_str.c srcs/env/ft_strclear.c srcs/env/ft_strdelone.c srcs/env/ft_strtotallen.c
 */
int	main(void)
{
	t_env	*var1;
	t_env	*var2;
	char	**tab;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;
	char	*str7;
	char	*str8;
	char	*str9;

	var1 = malloc(sizeof(*var1));
	var2 = malloc(sizeof(*var2));
	if (!(var1 && var2))
		return (1);
	var1->key = ft_strdup("a");
	var1->value = ft_strdup("var1");
	var2->key = ft_strdup("b");
	var2->value = NULL;
	var1->next = var2;
	var2->next = NULL;
	tab = malloc(10 * sizeof(*tab));
	str1 = ft_strdup("Test variable $a for expansion\n");
	str2 = ft_strdup("Test $b for no value\n");
	str3 = ft_strdup("Test variable \"$a some word\" inside quotes\n");
	str4 = ft_strdup("Test variable \" nested \'$a\' quotes \"\n");
	str5 = ft_strdup("Test \'$a\' no expansion\n");
	str6 = ft_strdup("Test nothing to expand\n");
	str7 = ft_strdup("Test $ alone\n");
	str8 = ft_strdup("Test \'$\' in single quotes\n");
	str9 = ft_strdup("Test \"$\" in double quotes\n");
	tab[0] = str1;
	tab[1] = str2;
	tab[2] = str3;
	tab[3] = str4;
	tab[4] = str5;
	tab[5] = str6;
	tab[6] = str7;
	tab[7] = str8;
	tab[8] = str9;
	tab[9] = NULL;
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
	ft_putstr_fd(tab[4], 1);
	ft_putstr_fd(tab[5], 1);
	ft_putstr_fd(tab[6], 1);
	ft_putstr_fd(tab[7], 1);
	ft_putstr_fd(tab[8], 1);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	free(tab[4]);
	free(tab[5]);
	free(tab[6]);
	free(tab[7]);
	free(tab[8]);
	free(tab);
	return (0);
}
