#include "minishell.h"

void    ignore_sigint(void)
{
    struct sigaction	ign;

	sigemptyset(&ign.sa_mask);
	ign.sa_handler = SIG_IGN;
	ign.sa_flags = 0;
	sigaction(SIGINT, &ign, NULL);
}