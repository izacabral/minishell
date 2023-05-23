/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_export_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchastin <vchastin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:01:37 by vchastin          #+#    #+#             */
/*   Updated: 2023/05/23 09:01:39 by vchastin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "unit_test.h"

void	teste_print_env(t_env *env)
{
	t_env  *tmp;
	int		error;

	tmp = env;
	error = 1;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putchar_fd('\n', 1);
		}
		if (ft_strncmp(tmp->key, "1dawe", 5))
			error = 1;
		else if (ft_strncmp(tmp->key, "IZA", 3))
			error = 2;
		tmp = tmp->next;
	}
	printf("=============================");
	if (error == 0)
		printf("Chave adicionada com sucesso\n");
	else if (error == 1)
		printf("Chave 1dawe não foi adicionada\n");
	else if (error == 2)
		printf("Chave IZA foi adicionada, mas o valor não por conter espaço\n");
}

void	teste_export(t_shell data)
{
	char *str1[] = {"export","student=vchastin"};
	char *str2[] = {"export","DANIEL=33"};
	char *str3[] = {"export","1dawe=vchastin"};
	char *str4[] = {"export","IZA= 22"};
	export_builtins(2, str1, data);
	export_builtins(2, str2, data);
	export_builtins(2, str3, data);
	export_builtins(2, str4, data);
	teste_print_env(data.lst_env);
	char *s[] = {"export"};
	export_builtins(1, s, data);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	data; // Struct global (s_shell/t_shell)
	(void)(argv);
	(void)(argc);

	init_shell(&data, envp);
    teste_export(data);
    del_lst(data.lst_env);
	return (0);
}
