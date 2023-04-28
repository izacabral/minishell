#include "minishell.h"
#include "types.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	open_file(char *p, t_token t, int append)
{
	const mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (t == IN)
		return (open(p, O_RDONLY | O_CREAT, mode));
	if (t == HDOC)
		return (open(p, O_RDONLY | O_CREAT, mode));
	if (t == OUT)
	{
		if (append)
			return (open(p, O_WRONLY | O_CREAT | O_APPEND, mode));
		return (open(p, O_WRONLY | O_CREAT, mode));
	}
	return (-1);
}

t_file	*new_file(char *path, t_token t, int append)
{
	t_file	*new;

	if (!path)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->file_name = path;
	new->fd = open_file(new->file_name, t, append);
	if (new->fd < 0)
	{
		free_file(new);
		return (NULL);
	}
	return (new);
}

void	free_file(t_file *f)
{
	if (!f)
		return ;
	close(f->fd);
	free(f->file_name);
	f->file_name = NULL;
	free(f);
	f = NULL;
}
