#include "libft.h"
#include "minishell.h"
#include "env.h"
#include "types.h"

static int	sentence_lenght(char *sentence, t_quotes quote);
static void	split_sentence(t_string **lst, t_repl *repl, t_env *env);
static void	stash_string(t_string **lst, char *sentence, int size);
static int	expvar(t_string **lst, char *var, t_env *env);

/*
 * Fn		: scan_sentence(char *sentence, t_env *env)
 * Scope	: divide uma string em blocos, aplicando as expansões
 * Input	: char *sentence - string a ser lida e expandida
 *			: t_env * - lista com as variáveis de ambiente
 * Output	: t_string * - lista de strings, com a string de entrada divida em blocos a serem reunidos posteriormente
 * Errors	: NULL - a string de entrada não tem expansões a serem feitas
 * Uses		: expand_sentence()
 */
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

// determina o escopo a ser lido
// incrementa até encontrar uma aspas ou até o final da string
// se estiver em um contexto de aspas, incrementa até encontrar a aspas de fechamento
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

// divide a string em blocos quando encontra $
// se estiver em um contexto de <"> ou <sem aspas>, expande a variável
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

// guarda a string até o char anterior a $
static void	stash_string(t_string **lst, char *sentence, int size)
{
	char	*to_stash;

	to_stash = ft_substr(sentence, 0, size);
	ft_stradd_back(lst, ft_strnew(to_stash, size));
}

// expande a variável
// se o $ for seguido de espaço em branco ou de aspas, não faz expansão e guarda $
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
