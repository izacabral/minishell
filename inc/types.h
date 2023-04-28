#ifndef TYPES_H
# define TYPES_H
# include <stdlib.h>

typedef struct s_string
{
	size_t			length;
	char			*content;
	struct s_string	*last;
	struct s_string	*next;
}					t_string;

typedef enum e_token
{
	ERROR,
	CMD,
	FILE_TK,
	PIPE,
	IN,
	OUT,
	HDOC,
}	t_token;

typedef struct s_data
{
	int				token;
	void			*word;
	struct s_data	*next;
}					t_data;

typedef struct s_file
{
	int		fd;
	char	*file_name;
}			t_file;

typedef struct s_cmd
{
	int			token;
	t_string	*cmd;
	int			cat;
	t_file		*output;
	t_file		*input;
	t_file		*hdoc;
}				t_cmd;

t_data		*new_data(void *ptr, t_token t);
void		data_addback(t_data **lst, t_data *new);
t_data		*data_find_last(t_data *lst);
void		data_clear(t_data **lst);
t_cmd		*new_cmd(t_string *cmd);
void		cmd_redirect(t_cmd *cmd, t_file *f, t_token t, int	cat);
void		free_cmd(t_cmd *cmd);
t_file		*new_file(char *path, t_token t, int append);
void		free_file(t_file *f);
t_string	*ft_strnew(char *str, size_t length);
void		ft_stradd_front(t_string **lst, t_string *new);
void		ft_stradd_back(t_string **lst, t_string *new);
void		ft_strsetlast(t_string *lst, t_string *laststr);
int			ft_strsize(t_string *lst);
void		ft_strdelone(t_string *lst, void (*del)(void *));
void		ft_strclear(t_string **lst, void (*del)(void *));
void		freetab(void **ptr);

#endif
