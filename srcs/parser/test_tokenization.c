#include <readline/readline.h>
#include <stdio.h>
#include "minishell.h"
#include "testing.h"
#include "types.h"

// Funcção para testar scan_line().
// Compilar com os arquivos:
// srcs/parser/debug_print.c srcs/parser/isdelim.c srcs/parser/isquotes.c srcs/parser/scan_line.c srcs/parser/test_tokenization.c srcs/parser/which_delim.c srcs/data_types/t_token.c
int	main(void)
{
	char	*buffer;
	int		ret;
	t_token	*lst;

	buffer = NULL;
	lst = NULL;
	while (1)
	{
		buffer = readline("Press <Ctrl+D> to exit~ ");
		if (!buffer)
			break ;
		ret = scan_line(&lst, buffer);
		printf("Scanner return= %i\n", ret);
		print_data((void *)lst, TOKEN);
		clear_token(&lst);
	}
	return (0);
}
