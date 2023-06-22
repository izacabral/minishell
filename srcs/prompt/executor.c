/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:52:16 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/20 00:08:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_executor_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	g_global = errno;
}

void	exec_sentence(t_sentence *sentence, t_shell *data)
{
	if (sentence->fd_i != 0)
		dup2(sentence->fd_i, 0);
	if (sentence->fd_o != 1)
		dup2(sentence->fd_o, 1);
	close_fds(data);
	exec_command(sentence->args[0], sentence->args, data);
}

void	wait_sentences(t_shell *data)
{
	t_sentence	*tmp;
	int			status;

	tmp = data->lst_sentence;
	g_global = 0;
	while (tmp)
	{
		waitpid(tmp->pid, &status, 0);
		if (WIFEXITED(status))
			g_global = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			g_global = 128 + WTERMSIG(status);
		if (tmp->args == NULL)
			g_global = 127;
		tmp = tmp->next;
	}
}

void	executor(t_shell *data)
{
	t_sentence	*tmp;
	int			count;
	int			pid;

	tmp = data->lst_sentence;
	count = 0;
	while (count < data->sentence_count)
	{
		if (tmp->fd_i != -1 && tmp->fd_o != -1 && tmp->args[0])
		{
			pid = fork();
			if (pid == -1)
				print_executor_error();
			if (pid == 0)
				exec_sentence(tmp, data);
			tmp->pid = pid;
		}
		count++;
		tmp = tmp->next;
	}
	close_fds(data);
	wait_sentences(data);
}
