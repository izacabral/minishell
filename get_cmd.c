#include "defines.h"
#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static char	*test_file(char *path, char *file)
{
	char	*buffer;

	if (!path || !file)
		return (NULL);
	buffer = ft_strjoin(path, file);
	if (buffer && !access(buffer, F_OK))
		return (buffer);
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*get_cmd(char *buffer, char *line)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	buffer = test_file(LOCBIN, line);
	if (buffer)
		return (buffer);
	buffer = test_file(USRBIN, line);
	if (buffer)
		return (buffer);
	buffer = test_file(BIN, line);
	if (buffer)
		return (buffer);
	return (NULL);
}
