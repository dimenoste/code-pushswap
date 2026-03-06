/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:36:13 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 13:37:06 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_cases(t_stack *a, t_op_list *ops)
{
	if (a->length <= 1)
		return (1);
	if (a->length == 2)
	{
		sort_two(a, ops);
		return (1);
	}
	if (a->length == 3)
	{
		sort_three(a, ops);
		return (1);
	}
	return (0);
}

static size_t	prepare_lis(t_stack *a, t_op_list *ops)
{
	size_t	best_pos;
	size_t	nb_lis;

	best_pos = find_best_lis(a);
	rotate_to_top(a, best_pos, ops);
	nb_lis = add_lis_to_nodes(a, &best_pos);
	return (nb_lis);
}

static void	push_non_lis(t_stack *a, t_stack *b, t_op_list *ops, size_t nb_lis)
{
	size_t	target;
	t_cost	best;

	target = a->length - nb_lis;
	while (b->length < target)
	{
		if (!a->head->is_lis)
		{
			best = find_cheapest_non_lis(a, b);
			execute_rotations(a, b, ops, &best);
			push(a, b, ops);
		}
		else
			rotate(a, ops);
	}
}

void	lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	nb_lis;

	if (handle_small_cases(a, ops))
		return ;
	add_index_node(a);
	nb_lis = prepare_lis(a, ops);
	push_non_lis(a, b, ops, nb_lis);
	push_all_to_a(a, b, ops);
}
