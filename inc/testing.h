#ifndef TESTING_H
# define TESTING_H
# include "minishell.h"
# include <stdio.h>

typedef enum e_test
{
	UNDEFINED,
	TOKEN,
}	t_test;

void	print_data(void *ptr, t_test t);

#endif
