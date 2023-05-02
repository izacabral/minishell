#include "libft.h"
#include "minishell.h"
#include "types.h"
#include <ctype.h>
#include <stdlib.h>

static int	token_lenght(char *token);
static int	token_lenght_quotes(char *token, char quote);

static int	add_token(t_token **lst, char *str, int lenght)
{
	char	*value;
	t_tkn	token;

	if (lenght < 0)
		return (lenght);
	value = malloc((lenght + 1) * sizeof(*value));
	if (!value)
		return (-1);
	ft_memcpy(value, str, lenght);
	value[lenght] = '\0';
	token = WORD;
	if (isdelim(*value))
		token = which_delim(value);
	addback_token(lst, new_token(value, token));
	return (lenght);
}

static int	delim_lenght(char *delim, char d)
{
	if (d == '|')
		return (1);
	if (*(delim + 1) == d)
		return (2);	// É >> OU <<
	return (1);		// É > OU <
}

// Bloco começa com aspas (simples ou duplas)
static int	token_lenght_quotes(char *token, char quote)
{
	int	len;

	len = 1;
	while (token[len] && token[len] != quote)
		len++;
	if (!token[len])
		return (-2);
	if (!isspace(token[len + 1]) || !isdelim(token[len + 1]))
		len += token_lenght(&token[len + 1]);
	return (len + 1);
}

// Bloco não começa com aspas - É palavra ou delimitador
static int	token_lenght(char *token)
{
	int	len;
	int	error;

	if (isdelim(*token))
		return (delim_lenght(token, *token));
	len = 0;
	while (token[len] && !ft_isspace(token[len]))
	{
		if (isquotes(token[len]))
		{
			error = token_lenght_quotes(&token[len], token[len]);
			if (error < 0)
				return (-2);
			len += error;
		}
		else
			len++;
		if (isdelim(token[len]))
			break ;
	}
	return (len);
}

/*
 * Fn		: scan_line(t_token **lst, char * line)
 * Scope	: divide linha de comando em tokens palavra ou delimitadores
 * Input	: t_token **lst - endereço da lista de tokens
 *			: char * - linha de comando (retorno da readline())
 * Output	: int (0) - nenhum erro encontrado
 * Errors	: int (-1) - erro na alocação
 *			: int (-2) - erro de sintaxe (aspas de fechamento não encontradas)
 * Uses		: WIP
 */
int	scan_line(t_token **lst, char *line)
{
	char	*start;	// Início do bloco
	int		i;		// Contador para a extensão do bloco

	start = line;
	while (*start)
	{
		while (*start && ft_isspace(*start))
			start++;
		if (isquotes(*start))
			i = token_lenght_quotes(start, *start);
		else
			i = token_lenght(start);
		i = add_token(lst, start, i);
		if (!*lst)
			i = -1;
		if (i < 0)
			return (i);
		start += i;
	}
	return (0);
}
