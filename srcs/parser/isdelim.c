int	isdelim(char c)
{
	const char	*delim = "|<>";

	while (*delim)
	{
		if (c == *delim)
			return (c);
		delim++;
	}
	return (0);
}
