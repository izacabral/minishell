#include "minishell.h"

int	main(void)
{
	char	*line;
	t_data	*data;

	setup_signals();
	line = NULL;
	data = NULL;
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
