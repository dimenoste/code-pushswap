/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:40:30 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 16:41:55 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_to_b(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	target;

	while (a->length > 0)
	{
		target = find_min_pos(a);
		rotate_to_top(a, target, ops);
		push(a, b, ops);
	}
}

void	simple_sort(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (handle_small_cases(a, ops))
		return ;
	assign_indices(a);
	push_all_to_b(a, b, ops);
	while (b->length > 0)
	{
		push(b, a, ops);
	}
}
