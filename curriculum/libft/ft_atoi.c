int	atoi(const char *nptr)
{
	int	nb;
	int	i;

	if (!nptr)
		return (0);
	i = 0;
	nb = 0;
	while (nptr[i])
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb);
}
