#include "testing.h"
#include "types.h"

void	error_redir(char *filename)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

int	open_reds(int token, t_sentence cmd, char *file_name) 
{
	int fd;
	(void)(cmd);

	if (!file_name)
		return (EXIT_FAILURE);
	if (token == OUT) 
	{
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		cmd.fd_o = fd;
	} else if (token == IN) {
		fd = open(file_name, O_RDONLY);
		cmd.fd_i = fd;
	} else if (token == APPEND) 
	{
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		cmd.fd_o = fd;
	}
	if (fd == -1) 
		error_redir(file_name);
	return fd;
}

static char	*find_filename(char *s, int redir)
{
	char 	*str;
	char 	*filename;
	int		pos;

	if (redir == IN)
		str = ft_strchr(s, '<');
	else if (redir == OUT)
		str = ft_strchr(s, '>');
	
	pos = (str - s) + 2;
	filename = ft_substr(s, pos , ft_strlen(s) - pos);
	return (filename);
}

void free_sentence(t_sentence* sentence) {
	if (sentence == NULL) {
		return;
	}
	if (sentence->args != NULL) {
		for (int i = 0; sentence->args[i] != NULL; i++) {
			free(sentence->args[i]);
		}
		free(sentence->args);
	}
	free(sentence);
} //trocar por clear_sentence

int	main(void)
{
	t_sentence *st = malloc(sizeof(t_sentence));
	if (st == NULL) 
		return -1;
	char 	*initial_args[] = {"blabla < input.txt", "beaba > output.txt"};
	int 	num_args = sizeof(initial_args) / sizeof(initial_args[0]);
	st->args = malloc((num_args + 1) * sizeof(char *));
	if (st->args == NULL) {
		free(st);
		return -1;
	}
	for (int i = 0; i < num_args; i++) {
		st->args[i] = ft_strdup(initial_args[i]);
		if (st->args[i] == NULL) {
			free_sentence(st);
			return -1;
		}
	}
	st->args[num_args] = NULL;
	st->fd_i = -2;
	st->fd_o = -2;
	int	i;

	i = -1;
	while (++i < num_args)
	{
		if (strstr(st->args[i], ">") != NULL)
			open_reds(OUT, *st, find_filename(st->args[i], OUT));
		else if (strstr(st->args[i], "<") != NULL)
			open_reds(IN, *st, find_filename(st->args[i], IN));
		else if (strstr(st->args[i], ">>") != NULL)
			open_reds(APPEND, *st, find_filename(st->args[i], APPEND));
		else
			return (-1);
	}
	free_sentence(st);
	return 0;
}