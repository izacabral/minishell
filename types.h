#ifndef TYPES_H
# define TYPES_H

typedef enum e_token
{
	ERROR,
	CMD,
	FILE,
	PIPE,
	REDR,
	HDOC,
}	t_token;

typedef struct s_data
{
	int				token;
	char			**cmd;
	struct s_data	*next;
}					t_data;

#endif
