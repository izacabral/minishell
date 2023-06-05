/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_builtin_cd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:21:41 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/05 12:35:52 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	test_cd(t_shell *data)
{
	int		ret;
	//char	*ptr;
	char	*path = "42";

//	ptr = NULL;
	if (cd(data, path) == 1)
		return (ret = 1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	data;
	(void)(av);
	(void)(ac);

	init_shell(&data, envp);
	if (test_cd(&data) == -1)
		return (1);
	clear_env(&data.lst_env);
	return (0);
}
