#include "minishell.h"
#include "unit_test.h"

void	teste_print_env(t_env *env, char *key)
{
	t_env  *tmp;
	int		error;

	tmp = env;
	error = 0;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putchar_fd('\n', 1);
		}
		if (ft_strncmp(tmp->key, key, ft_strlen(key)))
			error = 1;
		tmp = tmp->next;
	}
	printf("=============================");
	if (error == 1)
		printf("Chave %s não foi excluida\n", key);
	else
		printf("Chave %s foi excluida com sucesso\n", key);
}

void	teste_unset(t_shell data)
{
	printf("================PRINT VARIAVEL DE AMBIENTE=========================");
	teste_print_env(data.lst_env, "");
	printf("==============================================================");
	printf("\n");
	printf("\n");
	printf("\n");
	char *s[] = {"unset", "LS_COLORS"};
	unset_builtins(2, s, data);
	teste_print_env(data.lst_env, "LS_COLORS");
	teste_export(data);
	char *str1[] = {"unset", "student"};
	unset_builtins(2, str1, data);
	char *str2[] = {"unset", "DANIEL"};
	unset_builtins(2, str2, data);
	teste_print_env(data.lst_env, "student");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	data; // Struct global (s_shell/t_shell)
	(void)(argv);
	(void)(argc);

	init_shell(&data, envp);
	teste_unset(data);
	del_lst(data.lst_env);
	return (0);
}