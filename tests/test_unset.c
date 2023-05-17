#include "testing.h"

void	teste_unset(t_shell data)
{
	print_env(data.lst_env);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	char *s[] = {"unset", "LS_COLORS"};
	unset_builtins(2, s, data);
	print_env(data.lst_env);
}

void	init_shell(t_shell *data, char *envp[])
{
	data->line = NULL;
	data->lst_env = get_env(envp);
	data->lst_token = NULL;
	data->sentence_count = 0;
	//data->lst_sentence = NULL;
	data->pipe_count = 0;
	data->redirect_count = 0;
	data->pipes = NULL;
	data->reds = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	data; // Struct global (s_shell/t_shell)
	(void)(argv);
	(void)(argc);

	init_shell(&data, envp);
	teste_unset(data);
	free_env(data.lst_env);
	return (0);
}