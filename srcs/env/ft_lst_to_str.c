#include "minishell.h"

char	*ft_lst_to_str(t_string *lst)
{
	char	*str;
	size_t	length;
	int		i;

	length = ft_strtotallen(lst);
	str = malloc((length + 1) * sizeof(*str));
	str[length] = '\0';
	i = 0;
	while (lst)
	{
		if (lst->content)
			ft_memcpy(&str[i], lst->content, lst->length);
		i += lst->length;
		lst = lst->next;
	}
	return (str);
}
