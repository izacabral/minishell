#include "testing.h"

static void	print_token(t_token *cmd);

void	print_data(void *ptr, t_tkn t)
{
	if (t == WORD)
		print_token((t_token *)ptr);
}

static void	print_token(t_token *cmd)
{
	printf("Token = %i\n", cmd->tkn);
	printf("Word = %s\n", cmd->word);
	printf("\n\n");
}
