#include "testing.h"

static void	print_cmd(t_cmd *cmd);
static void	print_file(t_file *file);

void	print_data(void *ptr, t_token t)
{
	if (t == CMD)
		print_cmd((t_cmd *)ptr);
	if (t == FILE_TK)
		print_file((t_file *)ptr);
}

static void	print_cmd(t_cmd *cmd)
{
	t_string	*c;
	printf("Token = %i\n", cmd->token);
	printf("Append = %i\n", cmd->cat);
	printf("Output = %p\n", cmd->output);
	printf("Input = %p\n", cmd->input);
	printf("Heredoc = %p\n\n", cmd->hdoc);
	c = cmd->cmd;
	while (c)
	{
		printf("%s ", c->content);
		c = c->next;
	}
	printf("\n\n");
}

static void	print_file(t_file *file)
{
	printf("FD = %i\n", file->fd);
	printf("%s\n", file->file_name);
	printf("\n");
}
