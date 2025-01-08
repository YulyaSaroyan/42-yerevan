#include <stdlib.h>

int	ft_intlen(long n)
{
	int	len;
	
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int	len;

	num = n;
	len = ft_intlen(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
		str[0] = '0';
       	str[len] = '\0';
	while (num > 0)
	{
		str[--len] = num % 10;
		num /= 10;
	}
	return (str);
}
