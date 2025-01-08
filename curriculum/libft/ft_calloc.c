#include <stdlib.h>
#include <limits.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*space;
	size_t	total_size;

	if (nelem && elsize > INT_MAX / nelem)
		return (NULL);
	total_size = nelem * elsize;
	if (total_size == 0)
		return (NULL);
	space = malloc(total_size);
	if (!space)
		return (NULL);
	ft_bzero(space, total_size);
	return (space);
}
