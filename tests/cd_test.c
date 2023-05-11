/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:28:08 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/11 14:00:32 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	*pwd;
	char	*old_pwd;

	if (ac == 2 || ac == 3)
	{
		if (ac == 3)
		{
			if (strcmp(av[2], "-") == 0)
				printf("%s\n", old_pwd);
			else
				puts("minishell: invalid option\n");
		}
		old_pwd = strdup(getcwd(NULL, 0));
		chdir(av[1]);
		pwd = strdup(getcwd(NULL, 0));
		printf("old_pwd: %s\npwd: %s\n", old_pwd, pwd);
	}
	free(pwd);
	free(old_pwd);
	return (0);
}
