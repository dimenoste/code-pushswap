/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:39:32 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/04 14:55:24 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node	*current;
	size_t	i;

	if (is_empty_stack(stack))
	{
		printf("%s : empty stack\n", name);
		return ;
	}
	printf("[VALUES of Stack %s, length=%zu]: ", name, stack->length);
	current = stack->head;
	i = 0;
	while (i < stack->length)
	{
		printf("%d", current->value);
		if (i < (stack->length - 1))
			printf(" → ");
		current = current->next;
		i++;
	}
	printf("\n");
}

void	print_index_stack(t_stack *stack, const char *name)
{
	t_node	*current;
	size_t	i;

	if (is_empty_stack(stack))
	{
		printf("empty stack\n");
		return ;
	}
	printf("[INDEX  of Stack %s, length=%zu]: ", name, stack->length);
	current = stack->head;
	i = 0;
	while (i < stack->length)
	{
		printf("%zu", current->index);
		if (i < stack->length - 1)
			printf(" → ");
		current = current->next;
		i++;
	}
	printf("\n");
}

void	print_lis_stack(t_stack *stack, const char *name)
{
	t_node	*current;
	size_t	i;

	if (is_empty_stack(stack))
	{
		printf("empty stack\n");
		return ;
	}
	printf("[IS_LIS of Stack %s, length=%zu]: ", name, stack->length);
	current = stack->head;
	i = 0;
	while (i < stack->length)
	{
		printf("%d", current->is_lis);
		if (i < stack->length - 1)
			printf(" → ");
		current = current->next;
		i++;
	}
	printf("\n");
}

/*
	add node to stack and return 1 or 0
	if value in node is unique or not respectively
 */
int	is_node_unique(t_stack *stk, t_node *node)
{
	t_node	*orig_head;

	stack_add_back(stk, node);
	if (!stk || !node)
		return (0);
	orig_head = stk->head;
	while (stk->head != stk->tail)
	{
		if (stk->head->value == node->value)
		{
			stk->head = orig_head;
			return (0);
		}
		stk->head = stk->head->next;
	}
	stk->head = orig_head;
	return (1);
}

int	is_in_order(t_stack *stk)
{
	t_node	*current;

	if (!stk)
		return (1);
	else if (stk->length < 2)
		return (1);
	else
	{
		current = stk->head;
		while (current != stk->tail)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
	}
	return (1);
}
