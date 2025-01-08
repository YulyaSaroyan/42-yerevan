int ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	len;

	len = 0;
	while (dest[len])
		len++;
	if (len > size)
		return (len + size);
	i = 0;
	while (src[i] && i < size - len - 1)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len <= size)
		dest[len + i] = '\0';
	return (len + size);
}
