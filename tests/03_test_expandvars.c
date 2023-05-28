#include "minishell.h"

int	main(void)
{
	int ver = 0; // verificação de retorno do teste

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

	/* CRIAÇÃO DA T_ENV PARA TESTE */
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

	/* CRIAÇÃO DAS STRINGS PARA SEREM EXPANDIDAS */
	tab = malloc(10 * sizeof(*tab));
	str1 = ft_strdup("Test variable $a for expansion");
	str2 = ft_strdup("Test $b for no value");
	str3 = ft_strdup("Test variable \"$a some word\" inside quotes");
	str4 = ft_strdup("Test variable \" nested \'$a\' quotes \"");
	str5 = ft_strdup("Test \'$a\' no expansion");
	str6 = ft_strdup("Test nothing to expand");
	str7 = ft_strdup("Test $ alone");
	str8 = ft_strdup("Test \'$\' in single quotes");
	str9 = ft_strdup("Test \"$\" in double quotes");
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

	/* EXPANSÃO DAS VARIÁVEIS */
	expandvars(tab, var1);

	/* CRIAÇÃO DO ARRAY DE STRINGS COMO DEVERIAM FICAR */
	char *check[10];

	int i = 0;
	while (i < 10)
	{
		check[i] = NULL;
		i++;
	}
	check[0] = "Test variable var1 for expansion";
	check[1] = "Test  for no value";
	check[2] = "Test variable \"var1 some word\" inside quotes";
	check[3] = "Test variable \" nested 'var1' quotes \"";
	check[4] = "Test \'$a\' no expansion";
	check[5] = "Test nothing to expand";
	check[6] = "Test $ alone";
	check[7] = "Test \'$\' in single quotes";
	check[8] = "Test \"$\" in double quotes";

	/* COMPARA  TAB COM OS CHECKS ESPERADOS */
	i = 0;
	while (tab[i])
	{
		ver = ft_strncmp(check[i], tab[i], (ft_strlen(check[i]) + 1));
		ft_printf("tab[%d]:%s\n", i, tab[i]);
		if (ver != 0)
		{
			ver = i + 1;
			break;
		}
		i++;
	}

	/*LIBERAÇÃO */
	free(var1->key);
	free(var1->value);
	free(var2->key);
	free(var2->value);
	free(var1);
	free(var2);

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

	if (ver == 0)
		ft_printf("Expandvars functions is ok\n");
	else
		ft_printf("Something is wrong with expandvars function, ver= %d\n", ver);

	return (ver);
}
