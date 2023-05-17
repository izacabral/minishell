#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "minishell.h"
# include <unistd.h>
# include <stdio.h>

void	prt(int i, char *s);

void	prt(int i, char *s)
{
	while (*s)
		write(i, &*s++, 1);
	write(i, "\n", 1);
}

#endif
