#include "ft_printf.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		myprintf("number at index %d is %d\n", i, arr[i]);
		i++;
	}
}

int	*init_array(int *arr, int len, int val)
{
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = val;
		i++;
	}
	return (arr);
}
