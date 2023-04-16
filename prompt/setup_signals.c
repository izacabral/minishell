#include "minishell.h"
#include <signal.h>

//After a call to execve() the signals action are reset to default.
//SIGQUIT is set to be ignored here, but this might need to be changed,
// as CTRL+D can be used to quit a command in execution.
void	setup_signals(void)
{
	struct sigaction	int_action;
	struct sigaction	quit_action;

	sigemptyset(&int_action.sa_mask);
	sigemptyset(&quit_action.sa_mask);
	int_action.sa_handler = int_handler;
	quit_action.sa_handler = SIG_IGN;
	int_action.sa_flags = 0;
	quit_action.sa_flags = 0;
	sigaction(SIGINT, &int_action, NULL);
	sigaction(SIGQUIT, &quit_action, NULL);
}
