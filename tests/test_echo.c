#include "../inc/minishell.h"
#include "string.h"
/*Realizando alteções no codigo*/

/*Esta função e para checar os n, se caso na sequencia de n estiver um caracter diferente retorna 1 e vai pular linha*/
static int check_n(char *str) {
    int i = 0;

    if (str[0] == '-' && str[1]=='n') {
        i = 1;
        while (str[i] == 'n') {
            i++;
        }
		if(str[i-1] == 'n' && str[i+1])
			return 1;
		else
			return 0;
    }

}

int ft_echo(char **arg)
{
	int control;
	int i;
	i = 1;
	control = 0;
	if(arg[i] == NULL)
		ft_putstr_fd("\n",1);

	else if(ft_strncmp(arg[i], "-n", 2) == 0)
	{
			control = check_n(arg[i]);
			i++;
	}

	while(arg[i])
	{
		ft_putstr_fd(arg[i],1);
		i++;
		if(arg[i])
			 ft_putstr_fd(" ", 1);
	}
	if(control == 0)
		ft_putstr_fd("\n", 1);

}

int main(int argc, char **argv)
{ 
    ft_echo(argv);
}
