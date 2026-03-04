/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:12:08 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/28 01:06:43 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, t_op_list *ops)
{
	long	temp;
	int		tmp_idx;

	if (stack->length < 2)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	tmp_idx = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp_idx;
	if (stack->name == A)
		add_operation(ops, OP_SA);
	else
		add_operation(ops, OP_SB);
}

void	swap_both(t_stack *a, t_stack *b, t_op_list *ops)
{
	long	temp;
	int		tmp_idx;

	if (a->length >= 2)
	{
		temp = a->head->value;
		a->head->value = a->head->next->value;
		a->head->next->value = temp;
		tmp_idx = a->head->index;
		a->head->index = a->head->next->index;
		a->head->next->index = tmp_idx;
	}
	if (b->length >= 2)
	{
		temp = b->head->value;
		b->head->value = b->head->next->value;
		b->head->next->value = temp;
		tmp_idx = b->head->index;
		b->head->index = b->head->next->index;
		b->head->next->index = tmp_idx;
	}
	add_operation(ops, OP_SS);
}

void	push(t_stack *from, t_stack *to, t_op_list *ops)
{
	t_node	*elem;

	if (from->length == 0)
		return ;
	elem = stack_pop_front(from);
	stack_add_front(to, elem);
	if (to->name == A)
		add_operation(ops, OP_PA);
	else
		add_operation(ops, OP_PB);
}
