// https://www.youtube.com/watch?v=cjWnW0hdF1Y
// https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html
#include "ft_printf.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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