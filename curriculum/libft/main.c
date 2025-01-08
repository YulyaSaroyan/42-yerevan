#include <stdio.h>

char	**ft_split(char const *s, char c);

int main()
{
	char *str = "hello world";
    	printf("%s\n", str);

	char **arr = ft_split(str, ' ');
	int i = 0;
	while (arr[i])
    	{
       		printf("%s\n", arr[i]);
        	i++;   
    	}
    	return 0;
}
