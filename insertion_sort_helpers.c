/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:39:52 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/04 19:19:24 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node_at(t_stack *stk, size_t pos)
{
	t_node	*current;
	size_t	i;

	current = stk->head;
	i = 0;
	while (i < pos)
	{
		current = current->next;
		i++;
	}
	return (current);
}

size_t	find_min_pos(t_stack *stk)
{
	t_node	*current;
	size_t	min_idx;
	size_t	min_pos;
	size_t	i;

	current = stk->head;
	min_idx = current->index;
	min_pos = 0;
	i = 1;
	while (i < stk->length)
	{
		current = current->next;
		if (current->index < min_idx)
		{
			min_idx = current->index;
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	rotate_to_top(t_stack *stk, size_t pos, t_op_list *ops)
{
	size_t	i;

	if (pos == 0)
		return ;
	i = 0;
	if (pos <= stk->length / 2)
	{
		while (i < pos)
		{
			rotate(stk, ops);
			i++;
		}
	}
	else
	{
		while (i < stk->length - pos)
		{
			reverse_rotate(stk, ops);
			i++;
		}
	}
}
