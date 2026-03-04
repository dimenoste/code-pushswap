
// https://www.youtube.com/watch?v=cjWnW0hdF1Y
// https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html
#include "ft_printf.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("number at index %d is %d\n", i, arr[i]);
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

int	*lis(int *arr, int len_arr, int *len_lis)
{
	int	*d;
	int	*p;
	int	*subseq;
	int	i;
	int	j;
	int	ans;
	int	pos;
	int	end;

	d = NULL;
	ans = 0;
	pos = 0;
	i = 0;
	d = init_array(d, len_arr, 1);
	p = init_array(d, len_arr, -1);
	while (i < len_arr)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
				p[i] = j;
			}
			j++;
		}
		i++;
	}
	i = 1;
	ans = d[0];
	while (i < len_arr)
	{
		if (d[i] > ans)
		{
			ans = d[i];
			pos = i;
		}
		i++;
	}
	printf("lis length is %d\n", ans);
	*len_lis = ans;
	subseq = malloc(sizeof(int) * ans);
	if (!subseq)
		return (NULL);
	end = ans - 1;
	while (pos != -1)
	{
		subseq[end] = arr[pos];
		pos = p[pos];
		end--;
	}
	free(d);
	free(p);
	// print_array(subseq, ans);
	return (subseq);
}

t_bool	is_in_lis(int val, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (val == arr[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	add_lis_to_nodes(t_stack *stk)
{
	int		*arr;
	size_t	i;
	int		len_lis;
	int		*lis_subseq;
	t_node	*ptr_node;

	len_lis = 0;
	i = 0;
	if (!stk || stk->length < 2 || !stk->head)
		return (0);
	arr = copy_values(stk);
	lis_subseq = lis(arr, stk->length, &len_lis);
	ptr_node = stk->head;
	while (i < stk->length)
	{
		ptr_node->is_lis = is_in_lis(ptr_node->value, lis_subseq, len_lis);
		ptr_node = ptr_node->next;
		i++;
	}
	free(lis_subseq);
	free(arr);
	return (len_lis);
}
