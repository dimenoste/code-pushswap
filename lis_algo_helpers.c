/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:38:39 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 17:07:19 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	find_cheapest_non_lis(t_stack *a, t_stack *b)
{
	t_cost	best;
	t_cost	cur;
	t_node	*node;
	size_t	i;

	node = a->head;
	i = 0;
	best.cost_a = (int)a->length;
	best.cost_b = (int)b->length;
	while (i < a->length)
	{
		if (node->is_lis == 0)
		{
			cur.pos_a = i;
			cur.pos_b = find_insert_pos_b(b, node->index);
			set_cost_directions(&cur, a, b);
			if (total_cost(&cur) < total_cost(&best))
				best = cur;
		}
		node = node->next;
		i++;
	}
	return (best);
}

static size_t	eval_rot(int *arr, int n, int start)
{
	int		*tmp;
	size_t	len;
	size_t	pos;
	int		i;

	tmp = malloc(sizeof(int) * n);
	if (!tmp)
		return (0);
	i = 0;
	while (i < n)
	{
		tmp[i] = arr[(start + i) % n];
		i++;
	}
	free(get_lis(tmp, n, &len, &pos));
	free(tmp);
	return (len);
}

static int	*init_find_best_lis(t_stack *stk)
{
	int	*arr;

	if (!stk || stk->length < 2 || !stk->head)
		return (NULL);
	arr = copy_values(stk);
	if (!arr)
		return (NULL);
	return (arr);
}

size_t	find_best_lis(t_stack *stk)
{
	size_t	best_len;
	size_t	i;
	size_t	cur;
	size_t	best_pos;
	int		*arr;

	arr = init_find_best_lis(stk);
	if (!arr)
		return (0);
	best_len = 0;
	best_pos = 0;
	i = 0;
	while (i < stk->length)
	{
		cur = eval_rot(arr, stk->length, i);
		if (cur > best_len)
		{
			best_len = cur;
			best_pos = i;
		}
		i++;
	}
	free(arr);
	return (best_pos);
}
