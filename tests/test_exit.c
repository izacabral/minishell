/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:47:56 by fpeixoto          #+#    #+#             */
/*   Updated: 2023/05/15 19:56:34 by fpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_strdigit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_token	**lst, char **arg)
{
	ft_putstr_fd("exit\n", 1);
	if (arg[1] && ft_strdigit(arg[1]) == 0)
		ft_putstr_fd("numeric argument required\n", 1);
	clear_token(lst);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_token	*test;
	test = malloc (sizeof(t_token));
	ft_exit(&test, argv);
}
