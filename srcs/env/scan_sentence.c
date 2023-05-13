#include "libft.h"
#include "minishell.h"
#include "env.h"
#include "types.h"

static int	sentence_lenght(char *sentence, t_quotes quote);
static void	split_sentence(t_string **lst, t_repl *repl, t_env *env);
static void	stash_string(t_string **lst, char *sentence, int size);
static int	expvar(t_string **lst, char *var, t_env *env);

t_string	*scan_sentence(char *sentence, t_env *env)
{
	t_string	*output;
	t_repl		repl;
	int			i;

	output = NULL;
	i = 0;
	while (sentence[i])
	{
		repl.quote = which_quotes(sentence[i]);
		repl.old = &sentence[i];
		repl.old_sz = sentence_lenght(repl.old, repl.quote);
		split_sentence(&output, &repl, env);
		if (!output)
			return (NULL);
		i += repl.old_sz;
	}
	return (output);
}

static int	sentence_lenght(char *sentence, t_quotes quote)
{
	int	len;

	if (!quote)
	{
		len = 0;
		while (sentence[len] && which_quotes(sentence[len]) == NONE)
			len++;
		return (len);
	}
	len = 1;
	while (which_quotes(sentence[len]) != quote)
		len++;
	return (len + 1);
}

static void	split_sentence(t_string **lst, t_repl *repl, t_env *env)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = repl->old;
	i = 0;
	j = 0;
	while (tmp[j] && j < repl->old_sz)
	{
		if (tmp[j] == '$' && (repl->quote == DOUBLE || repl->quote == NONE))
		{
			if (j > 0)
				stash_string(lst, &tmp[i], j);
			j += (expvar(lst, &tmp[j], env) - 1);
			i += (j + 1);
		}
		j++;
	}
	if (!*lst && !tmp[j])
		return ;
	if (!&tmp[i])
		return ;
	repl->new = ft_substr(&tmp[i], 0, j - i);
	ft_stradd_back(lst, ft_strnew(repl->new, j - i));
}

static void	stash_string(t_string **lst, char *sentence, int size)
{
	char	*to_stash;

	to_stash = ft_substr(sentence, 0, size);
	ft_stradd_back(lst, ft_strnew(to_stash, size));
}

static int	expvar(t_string **lst, char *var, t_env *env)
{
	int		i;
	char	*value;
	int		len;

	i = 0;
	while (var[i] && !ft_isspace(var[i]) && !which_quotes(var[i]))
		i++;
	if (i == 1)
	{
		ft_stradd_back(lst, ft_strnew(ft_substr(var, 0, i), i));
		return (i);
	}
	value = get_value(&var[1], i - 1, env);
	len = 0;
	if (value)
		len = ft_strlen(value);
	ft_stradd_back(lst, ft_strnew(value, len));
	return (i);
}
