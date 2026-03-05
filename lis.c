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

static int	is_in_lis(int val, int *arr, size_t len)
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
static void	mark_lis_nodes(t_stack *stk, int *lis, size_t len)
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

static void	fill_dp(int *arr, int n, int *d, int *p)
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

static int	find_best_index(int *d, int n)
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

static int	*rebuild_lis(int *arr, int *p, int pos, int len)
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

int	*get_lis(int *arr, int n, size_t *len_lis, size_t *best_pos)
{
	int	*d;
	int	*p;
	int	pos;
	int	*seq;

	d = init_array(NULL, n, 1);
	p = init_array(NULL, n, -1);
	if (!d || !p)
		return (NULL);
	fill_dp(arr, n, d, p);
	pos = find_best_index(d, n);
	*len_lis = d[pos];
	*best_pos = (size_t)pos;
	seq = rebuild_lis(arr, p, pos, d[pos]);
	free(d);
	free(p);
	return (seq);
}

size_t	add_lis_to_nodes(t_stack *stk, size_t *best_pos)
{
	int *arr;
	int *lis;
	size_t len;

	if (!stk || stk->length < 2 || !stk->head)
		return (0);
	arr = copy_values(stk);
	if (!arr)
		return (0);
	lis = get_lis(arr, stk->length, &len, best_pos);
	if (!lis)
		return (free(arr), 0);
	mark_lis_nodes(stk, lis, len);
	free(lis);
	free(arr);
	return (len);
}