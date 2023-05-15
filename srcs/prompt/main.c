#include "libft.h"
#include "minishell.h"

/*Adicionado parametro envp*/
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

/*Alterei o argumento passado de init shell
Foi adicionada a função free_list()*/
int	main(int argc, char *argv[], char *envp[])
{
	t_shell	data; // Struct global (s_shell/t_shell)
	(void)(argv);
	(void)(argc);

	init_shell(&data, envp);
	setup_signals();
	while (1)
	{
		data.line = rl_gets(data.line);
		if (!data.line)
			break ;
		if (!ft_strncmp(data.line, "exit", 5))
		{
			free(data.line);
			break ;
		}
		launch_prog(&data);
		if (*data.line)
			add_history(data.line);
	}
	free_env(data.lst_env);
	return (0);
}