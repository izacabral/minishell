#include "libft.h"
#include "minishell.h"
#include "types.h"
#include <stdlib.h>

static char	*check_acess(char *path, char *cmd)
{
	char	*buffer;

	if (!path || !cmd)
		return (NULL);
	buffer = ft_strjoin(path, cmd);
	if (buffer && !access(buffer, F_OK))
		return (buffer);
	free(buffer);
	buffer = NULL;
	return (NULL);
}

static char	*test_cmd(char *cmd)
{
	char	*buffer;

	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	buffer = check_acess(LOCBIN, cmd);
	if (buffer)
		return (buffer);
	buffer = check_acess(USRBIN, cmd);
	if (buffer)
		return (buffer);
	buffer = check_acess(BIN, cmd);
	if (buffer)
		return (buffer);
	return (NULL);
}

static t_string	*make_strlst(char *cmd, char *args)
{
	t_string	*lst;
	char		*buffer;
	int			i;

	lst = ft_strnew(cmd, ft_strlen(cmd));
	while (ft_isspace(*args))
		args++;
	if (*args)
	{
		while (*args)
		{
			i = 0;
			while (args[i] && !ft_isspace(args[i]))
				i++;
			buffer = malloc((i + 1) * sizeof(*buffer));
			ft_strlcpy(buffer, args, i + 1);
			ft_stradd_back(&lst, ft_strnew(buffer, i));
			buffer = NULL;
			while (ft_isspace(args[i]))
				i++;
			args = &args[i];
		}
	}
	return (lst);
}

int	get_cmd(t_data **data, char *line)
{
	char	*tmp;
	char	*buffer;
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, line, i + 1);
	buffer = test_cmd(tmp);
	free(tmp);
	if (!buffer)
		return (0);
	cmd = new_cmd(make_strlst(buffer, &line[i]));
	data_addback(data, new_data((void *)cmd, CMD));
	return (1);
}
