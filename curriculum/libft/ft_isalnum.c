int ft_isalpha(int ch);
int ft_isdigit(int ch);

int ft_isalnum(int ch)
{
	return (ft_isalpha(ch) || ft_isdigit(ch));
}
