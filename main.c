#include "minishell.h"
#include "libft.h"

int	main(void)
{
	char	*line;
	char	*cmd;

	setup_signals();
	line = NULL;
	cmd = NULL;
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
		cmd = get_cmd(cmd, line);
		if (cmd)
			ft_putendl_fd(cmd, 1);
		else
			ft_putendl_fd("Not cmd", 1);
		if (*line)
			add_history(line);
	}
	return (0);
}
