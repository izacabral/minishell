/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:22:23 by dmatavel          #+#    #+#             */
/*   Updated: 2023/05/22 02:59:35 by dmatavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

/*
**   Fn     : pwd();
**   Scope  : prints the current absolute path in the stdout;
**   Input  : none;
**   Output : int (0) - expected output without errors;
**   Uses   : getcwd(), printf().
*/

int	pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		free(str);
		str = NULL;
		return (1);
	}
	else
	{
		printf("%s\n", str);
		free(str);
		str = NULL;
	}
	return (0);
}

/*
**   Fn     : main();
**   Scope  : main routine to run the  app;
**   Input  : none; 
**   Output : int (0) - expected output without errors;
**   Uses   : pwd().
*/

int	main(void)
{
	pwd();
	return (0);
}
