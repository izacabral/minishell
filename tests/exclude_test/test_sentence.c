#include "minishell.h"
#include "testing.h"

int	main(void)
{
	char	*buffer;
	t_token	*lst;
    t_token *tmp;
	
	lst = NULL;
    tmp = NULL;
	buffer = " cat teste2 < teste3 | ls | teste4 > clear ";
	
	scan_line(&lst, buffer);
    tmp = get_token_word(&lst);
    print_data((void *)tmp, TOKEN);
    int c_words = 0;
    c_words = count_tkn_words(&tmp);
    printf("total de palavras: %d\n", c_words);
    print_data((void *)tmp, TOKEN);
    
    char **teste;
    teste = tkn_to_sentence(&tmp);

    int i = 0;
    while (teste[i])
    {
        printf("teste[%d]: %s\n", i, teste[i]);
        i++;
    }
    print_data((void *)tmp, TOKEN);
	clear_token(&lst);
	
}