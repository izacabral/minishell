/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:22:23 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/09 15:54:40 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n > 0)
	{
		while (index < n - 1 && s1[index] == s2[index]
			&& (s1[index] || s2[index]))
		{
			index++;
		}
		return ((unsigned char) s1[index] - (unsigned char) s2[index]);
	}
	return (0);
}

int	pwd(char *cmd) // once we have an function thet eval the cmd's pwd() can be a void arg func
{
	if (ft_strncmp(cmd, "pwd", 3) != 0) // this if is not necessary in the final code
		return (1);
	else if (!getcwd(NULL, 0))
		return (1);
	else
		printf("%s\n", getcwd(NULL, 0));
	return (0);
}

/*
**   Fn     : main()
**   Scope  : main routine to run the  app;
**
**   Input  : int argc, char **argv
**   Output : int (0) - expected output without errors;
**
**   Errors : int (1) - i.e. no params passed;
**            int (2) - i.e. other errors;
**
**   Uses   : nome das funções vinculadas a essa;
*/

int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	else if (ac > 2)
		return (2);
	if (pwd(av[1]) != 0)
		return (2);
	return (0);
}
