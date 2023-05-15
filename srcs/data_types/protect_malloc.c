#include "minishell.h"

/*
 * Input			:void *arg - argument can be of any type
 * Scope			:checks whether dynamic memory allocation has occurred
 * Output			:none
 * 					:or
 * 					:error and exit
 */
void	protect_malloc(void *arg)
{
	if (arg == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(errno);
	}
}
