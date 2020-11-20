#include "libft.h"

size_t		ft_pos_i(char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}
