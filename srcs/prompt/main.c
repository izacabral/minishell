#include "minishell.h"

void	init_shell(t_shell *data)
{
	data->line = NULL;
	//init **lst_env
	data->lst_token = NULL;
	data->sentence_count = 0;
	//data->lst_sentence = NULL;
	data->pipe_count = 0;
	data->redirect_count = 0;
	data->pipes = NULL;
	data->reds = NULL;
}

int	main(void)
{
	t_shell	data; // Struct global (s_shell/t_shell)
	char 	*line;

	init_shell(&data);
	line = data.line;
	setup_signals();
	while (1)
	{
		line = rl_gets(line);
		if (!line)
			break ;
		if (!ft_strncmp(line, "exit", 5))
		{
			free(line);
			break ;
		}
		parse_line(&data, line);
		if (*line)
			add_history(line);
	}
	return (0);
}
