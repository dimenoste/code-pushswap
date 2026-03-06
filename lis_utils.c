// https://www.youtube.com/watch?v=cjWnW0hdF1Y
// https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html
#include "ft_printf.h"
#include "push_swap.h"

int	is_in_lis(int val, int *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (val == arr[i])
			return (1);
		i++;
	}
	return (0);
}

void	mark_lis_nodes(t_stack *stk, int *lis, size_t len)
{
	t_node	*node;
	size_t	i;

	node = stk->head;
	i = 0;
	while (i < stk->length)
	{
		node->is_lis = is_in_lis(node->value, lis, len);
		node = node->next;
		i++;
	}
}

void	fill_dp(int *arr, int n, int *d, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
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
}

int	find_best_index(int *d, int n)
{
	int	i;
	int	best;
	int	pos;

	i = 1;
	best = d[0];
	pos = 0;
	while (i < n)
	{
		if (d[i] > best)
		{
			best = d[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	*rebuild_lis(int *arr, int *p, int pos, int len)
{
	int	*seq;
	int	i;

	seq = malloc(sizeof(int) * len);
	if (!seq)
		return (NULL);
	i = len - 1;
	while (pos != -1)
	{
		seq[i--] = arr[pos];
		pos = p[pos];
	}
	return (seq);
}
