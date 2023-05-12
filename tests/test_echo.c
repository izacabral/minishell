#include "../inc/minishell.h"
/*Realizando alteção no codigo, não esta funcionando*/
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

int echo(char *argv)
{
    if(ft_strncmp(argv[0],"",0))
        printf("\n");
    else
    {
    while(*argv)
        printf("%c",*argv++);
    }
    if((ft_strncmp(argv[1],"-n",1)==1))
        printf("\n");
    return 1;
}

int main()
{
    char *test;
    test = "Test";
    echo(test);
}