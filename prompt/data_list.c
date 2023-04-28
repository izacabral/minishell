#include "minishell.h"

t_data	*new_data(t_token token, char **value)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->token = token;
	data->cmd = value;
	data->next = NULL;
	return (data);
}

void	data_clear(t_data **lst, void (*del)(void **))
{
	t_data *tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del((void **)tmp->cmd);
		tmp->cmd = NULL;
		free(tmp);
		tmp = NULL;
	}
}
