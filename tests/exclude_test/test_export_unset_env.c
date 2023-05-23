#include "testing.h"


void print_exp_unset_env(int argc, char *argv[], t_shell info)
{
    printf("Tente ./builtins export ou ./builtins export key=value\n");
    printf("ou ./builtins unset key.\n");
    if (ft_strncmp(argv[1], "export", 7) == 0)
    {
        export_builtins(argc, argv, info);
        if (argc != 2)
             print_env(info.lst_env);
    }   
    else if (ft_strncmp(argv[1], "unset", 5) == 0){
        unset_builtins(argc, argv, info);
        print_env(info.lst_env);
    }
    else if (ft_strncmp(argv[1], "env", 3) == 0)
        print_env(info.lst_env);
}

void	init_shell(t_shell *data, char *envp[])
{
	data->line = NULL;
	data->lst_env = get_env(envp);
	data->lst_token = NULL;
	data->sentence_count = 0;
	data->pipe_count = 0;
	data->redirect_count = 0;
	data->pipes = NULL;
	data->reds = NULL;
}

int main(int argc, char *argv[], char *envp[]) {
    t_shell  info;
    if (argc == 1)
    {
        printf("Tente ./builtins export ou ./builtins export key=value\n");
        printf("ou ./builtins unset key\n");
        return (0);
    }
    init_shell(&info, envp);
    print_exp_unset_env(argc, argv, info);
    return (0);
}