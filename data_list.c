#include "minishell.h"
#include <stdlib.h>

t_data	*data_find_last(t_data *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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

void	data_addback(t_data **lst, t_data *new)
{
	t_data *tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = data_find_last(*lst);
		tmp->next = new;
	};
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
	}
	*lst = NULL;
}
