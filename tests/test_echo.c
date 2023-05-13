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

int echo(char **arg)
{
    int i;
    i = 1;

    while(arg[i])
    {
        printf("%s",arg[i]);
        i++;
		if(arg[i])
			printf(" ");
			printf("\n");
				
    }
}


int main(int argc, char **argv)
{ 
    echo(argv);
}
