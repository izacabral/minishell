#include "minishell.h"

static int	get_token(t_data **data, char *line)
{
	if (get_cmd(data, line))
		return (1);
	return (0);
}

// Recursividade precisa ser implementada para leitura de vários tokens.
void	parser_line(t_data **data, char *line)
{
	int	i;

	while (ft_isspace(*line))
		line++;
	if (!*line)
		return ;
	if (get_token(data, line))
	{
		// Apenas para debug
		i = -1;
		ft_printf("token = %i\n", (*data)->token);
		while ((*data)->cmd[++i])
			ft_printf("%s\n", (*data)->cmd[i]);
	}
	if (*data)
		data_clear(data, freetab);
}
