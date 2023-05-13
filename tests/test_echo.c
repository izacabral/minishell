#include "../inc/minishell.h"
#include "string.h"
/*Realizando alteções no codigo*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((n > 0) && ((s1[i]) || (s2[i])))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
		n--;
	}
	return (0);
}

static int check_n(char *str) {
    int i = 0;

    if (str[0] == '-' && strcmp(str + 1, "n") == 0) {
        i = 1;
        while (str[i] == 'n') {
            i++;
        }
    }

    return i;
}

int echo(char **arg)
{
    int i;
	int control;
	control = 0;
    i = 1;

	if(arg[1] == NULL)
	{
		printf("\n");
		return 0;
	}
	
	if(strcmp(arg[1],"-n") == 0)
		{
			control = 1;
			i++;
		}

    while(arg[i])
    {
        printf("%s",arg[i]);
        i++;
		if(arg[i])
			printf(" ");	
		if(control == 0)
			printf("\n");
    }
}


int main(int argc, char **argv)
{ 
    echo(argv);
}
