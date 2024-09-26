/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:53:38 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/11 22:24:42 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

int	is_uppercase(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	return (0);
}

int	is_alphanumeric(char ch)
{
	if ((ch >= '0' && ch <= '9') || (is_lowercase(ch) || is_uppercase(ch)))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_uppercase(str[i]))
			str[i] += 32;
		i++;
	}
	while (str[j])
	{
		if (j == 0 && is_lowercase(str[j]))
			str[j] -= 32;
		if (is_lowercase(str[j]) && !is_alphanumeric(str[j - 1]))
			str[j] -= 32;
		j++;
	}
	return (str);
}
