#include "types.h"
#include <stdlib.h>

t_cmd	*new_cmd(t_string *cmd)
{
	t_cmd	*new;

	if (!cmd)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->token = CMD;
	new->cmd = cmd;
	new->cat = 0;
	new->output = NULL;
	new->input = NULL;
	new->hdoc = NULL;
	return (new);
}

void	cmd_redirect(t_cmd *cmd, t_file *f, t_token t, int	cat)
{
	if (t == IN)
		cmd->input = f;
	if (t == HDOC)
		cmd->hdoc = f;
	if (t == OUT)
	{
		if (cat)
			cmd->cat = 1;
		cmd->output = f;
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	ft_strclear(&cmd->cmd, free);
	if (cmd->input)
		free_file(cmd->input);
	if (cmd->output)
		free_file(cmd->output);
	if (cmd->hdoc)
		free_file(cmd->hdoc);
	free(cmd);
	cmd = NULL;
}
