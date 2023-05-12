#include "../inc/minishell.h"

int echo(char *argv)
{
    if(argv=="")
        printf("\n");
    else
    {
    while(*argv)
        printf("%c",*argv++);
    }
    printf("\n");
    return 1;
}

int main()
{
    echo("Felipe");
}