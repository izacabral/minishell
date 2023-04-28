#include "minishell.h"
// Apenas para debug
#include "testing.h"

static int	get_token(t_data **data, char *line)
{
	if (get_cmd(data, line))
		return (1);
	return (0);
}

// Recursividade precisa ser implementada para leitura de vários tokens.
void	parse_line(t_data **data, char *line)
{
	t_data	*tmp;

	while (ft_isspace(*line))
		line++;
	if (!*line)
		return ;
	if (get_token(data, line))
	{
		// Apenas para debug
		tmp = *data;
		while (tmp)
		{
			print_data(tmp->word, tmp->token);
			tmp = tmp->next;
		}
	}
	if (*data)
		data_clear(data);
}
