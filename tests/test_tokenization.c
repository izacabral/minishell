// Função para testar scan_line().
// Compilar com os arquivos:
// tests/debug_print.c srcs/parser/isdelim.c srcs/parser/isquotes.c srcs/parser/scan_line.c tests/test_tokenization.c srcs/parser/which_delim.c srcs/data_types/t_token.c

//#include <readline/readline.h>
//#include <stdio.h>
#include "minishell.h"
//#include "types.h"

typedef enum e_test
{
	UNDEFINED,
	TOKEN,
}	t_test;

static void	print_token(t_token *cmd)
{
	while (cmd)
	{
		printf("Token = %i\n", cmd->tkn);
		printf("Word = %s\n", cmd->word);
		printf("\n");
		cmd = cmd->next;
	}
	printf("\n");
}

void	print_data(void *ptr, t_test t)
{
	if (t == TOKEN)
		print_token((t_token *)ptr);
}

int	main(void)
{
	char	*buffer;
	int		ret;
	t_token	*lst;

	buffer = NULL;
	lst = NULL;
	goto end; // Bypass
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
	end: //Bypass
	printf("Bypass inserted to avoid infinite loop. Please review this code.\n");
	ret = 1;
	return (ret);
}
