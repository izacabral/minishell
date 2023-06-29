/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:52:16 by izsoares          #+#    #+#             */
/*   Updated: 2023/06/22 03:34:19 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_executor_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	g_global = 127;
}

void	exec_sentence(t_sentence *sentence, t_shell *data)
{
	default_signals();
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

	ft_printf("begin wait sentences, g_global=%i\n", g_global);
	tmp = data->lst_sentence;
	status = 0;
	while (tmp)
	{
		if (tmp->args[0])
		{
			ft_printf("enter first if wait sentences, g_global=%i\n", g_global);
			g_global = 0;
			ft_printf("STATUS=%i\n", status);
			int ret = 0;
			ret = waitpid(tmp->pid, &status, 0);
			ft_printf("ret %d\n", ret);
			ft_printf("Father read childs pid=%i\n", tmp->pid);
			ft_printf("STATUS=%i\n", status);
			if (WIFSIGNALED(status))
			{
				//if (WTERMSIG(status) == 11)
				//{
				//	g_global = 130;
				//	ft_printf("enter third if-if wait sentences, g_global=%i\n", g_global);
				//}
				//else
				{
					g_global = 128 + WTERMSIG(status);
					ft_printf("enter third if-else wait sentences, g_global=%i\n", g_global);
				}
			}
			else if (WIFEXITED(status))
			{
				g_global = WEXITSTATUS(status);
				ft_printf("enter second if wait sentences, g_global=%i\n", g_global);
			}
		}
		tmp = tmp->next;
	}
}

void	exec_one(t_sentence *tmp, t_shell *data, t_builtin builtin)
{
	default_signals();
	if (tmp->fd_i == -1 || tmp->fd_o == -1)
		return ;
	if (builtin)
		call_builtin(tmp->args, data, builtin);
}

void	executor(t_shell *data)
{
	t_sentence	*tmp;
	t_builtin	builtin;

	tmp = data->lst_sentence;
	builtin = isbuiltin(tmp->args[0]);
	if (data->sentence_count == 1 && builtin > ENV)
		exec_one(tmp, data, builtin);
	else
	{
		while (tmp)
		{
			if (tmp->fd_i != -1 && tmp->fd_o != -1 && tmp->args[0])
			{
				tmp->pid = fork();
				if (tmp->pid == -1)
					print_executor_error(strerror(errno));
				if (tmp->pid == 0)
				{
					ft_printf("child pid=%i\n", getpid());
					exec_sentence(tmp, data);
				}
			}
			tmp = tmp->next;
		}
	}
	close_fds(data);
	wait_sentences(data);
	ft_printf("after wait sentences, global=%i\n", g_global);
	setup_signals();
}
