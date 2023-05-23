#include "minishell.h"

int	main(void)
{
	char	*buffer;
	t_token	*lst;
    t_token *tmp;
    t_sentence *lst_sen;

    buffer = NULL;
	lst = NULL;
    tmp = NULL;
    lst_sen = NULL;

    /* MODELOS DE BUFFER PARA TESTE */
    //buffer = "< < teste | como | fica";
    //buffer = " --$a\" \"$a-- ";
    //buffer = "\"\"teste\"\"";
    //buffer = " Test variable \" nested \'$a\' quotes \" ";
	buffer = " Test variable $a for expansion < Test \'$a\' no expansion | \"\"ls\"\" | \"\'teste4\'\" > clear ";

    /* CRIAÇÃO DA LISTA DE TOKENS */
	scan_line(&lst, buffer);

    /* CRIAÇÃO DA T_ENV PARA TESTE */
    t_env	*var1;
	t_env	*var2;
	var1 = malloc(sizeof(*var1));
	var2 = malloc(sizeof(*var2));
	if (!(var1 && var2))
		return (1);
	var1->key = ft_strdup("a");
	var1->value = ft_strdup("var1");
	var2->key = ft_strdup("b");
	var2->value = NULL;
	var1->next = var2;
	var2->next = NULL;

    /* CRIAÇÃO DA LISTA DE SENTENÇAS*/
    create_sentences(var1, &lst, &lst_sen);

    /* PRINTA A LISTA DE SENTENÇAS*/
    while (lst_sen)
    {
        ft_printf("\n");
        char **teste = lst_sen->args;
        int i;
        i = 0;
        while (teste[i])
        {
            ft_printf("teste[%d]: %s\n", i, teste[i]);
            i++;
        }
        teste = NULL;
        ft_printf("previus: %p\n", lst_sen->previous);
        ft_printf("atual: %p\n", lst_sen);
        ft_printf("next: %p\n", lst_sen->next);
        lst_sen = lst_sen->next;

    }

    /* LIBERAÇÃO DA T_ENV */
    free(var1->key);
	free(var1->value);
	free(var2->key);

	free(var1);
	free(var2);

    /* LIBERAÇÃO DA LISTA DE TOKENS */
   	clear_token(&lst);

    /* LIBERAÇÃO DA LISTA DE SETENÇAS */
   	clear_sentence(&lst_sen);
    free(lst_sen);

}
