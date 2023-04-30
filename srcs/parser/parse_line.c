#include "minishell.h"
// Apenas para debug
#include "testing.h"

static int	get_token(t_token **data, char *line)
{
	if (get_cmd(data, line))
		return (1);
	return (0);
}

// Recursividade precisa ser implementada para leitura de vários tokens.
void	parse_line(t_shell *data, char *line)
{
	t_token	*tmp;

	while (ft_isspace(*line))
		line++;
	if (!*line)
		return ;
	if (get_token(&data->lst_token, line))
	{
		// Apenas para debug
		tmp = data->lst_token;
		while (tmp)
		{
			print_data(tmp->word, tmp->tkn);
			tmp = tmp->next;
		}
	}
	if (data->lst_token)
		clear_token(&data->lst_token);
}
