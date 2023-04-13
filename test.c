#include "libft.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	const char	*path = "/usr/bin/";
	char		*cmd;

	cmd = ft_strjoin(path, argv[1]);
	if (!access(cmd, F_OK))
		write(1, "OK", 2);
	free(cmd);
	(void)argc;
	return (0);
}
