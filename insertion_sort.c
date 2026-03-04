/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:08:07 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/28 01:26:27 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_op_list *ops)
{
	if (a->head->value > a->head->next->value)
		swap(a, ops);
}

void	sort_three(t_stack *a, t_op_list *ops)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->tail->value;
	if (first > second && second < third && first < third)
		swap(a, ops);
	else if (first > second && second > third)
	{
		swap(a, ops);
		reverse_rotate(a, ops);
	}
	else if (first > second && first > third)
		rotate(a, ops);
	else if (first < second && second > third && first < third)
	{
		swap(a, ops);
		rotate(a, ops);
	}
	else if (first < second && second > third)
		reverse_rotate(a, ops);
}

static void	push_cheapest_to_b(t_stack *a, t_stack *b, t_op_list *ops)
{
	t_cost	best;

	best = find_cheapest(a, b);
	execute_rotations(a, b, ops, &best);
	push(a, b, ops);
}

void	insertion_sort(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (a->length <= 1)
		return ;
	if (a->length == 2)
	{
		sort_two(a, ops);
		return ;
	}
	if (a->length == 3)
	{
		sort_three(a, ops);
		return ;
	}
	assign_indices(a);
	while (a->length > 3)
		push_cheapest_to_b(a, b, ops);
	sort_three(a, ops);
	push_all_to_a(a, b, ops);
}
