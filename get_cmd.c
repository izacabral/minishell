#include "defines.h"
#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

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

static char	**make_tab(char *cmd, char *args)
{
	char	**tab;
	char	*buffer;

	while (ft_isspace(*args))
		args++;
	if (!*args)
	{
		tab = malloc(2 * sizeof(*tab));
		if (!tab)
			return (NULL);
		tab[0] = cmd;
		tab[1] = NULL;
	}
	else
	{
		buffer = ft_strdup(args);
		tab = malloc(3 * sizeof(*tab));
		if (!(tab && buffer))
			return (NULL);
		tab[0] = cmd;
		tab[1] = buffer;
		tab[2] = NULL;
	}
	return (tab);
}

int	get_cmd(t_data **data, char *line)
{
	char	*tmp;
	char	*buffer;
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
	data_addback(data, new_data(CMD, make_tab(buffer, &line[i])));
	return (1);
}
