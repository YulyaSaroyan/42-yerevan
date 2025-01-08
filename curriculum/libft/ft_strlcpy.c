int ft_strlcpy(char *dest, char *src, int size)
{
	int	len;
	int	i;

	while (src[len])
		len++;
	if (!size)
		return (len);
	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
