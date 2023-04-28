#include "types.h"

t_data	*data_find_last(t_data *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_data	*new_data(void *ptr, t_token t)
{
	t_data	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->token = t;
	new->word = ptr;
	new->next = NULL;
	return (new);
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

static void	data_freeptr(void *ptr, t_token token)
{
	if (token == CMD)
		free_cmd((t_cmd *)ptr);
	if (token == FILE_TK)
		free_file((t_file *)ptr);
}

void	data_clear(t_data **lst)
{
	t_data	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		data_freeptr(tmp->word, tmp->token);
		free(tmp);
		tmp = NULL;
	}
}
