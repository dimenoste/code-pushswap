/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:59:23 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/02 18:27:51 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_cost_directions(t_cost *c, t_stack *a, t_stack *b)
{
	if (c->pos_a <= a->length / 2)
		c->cost_a = (int)c->pos_a;
	else
		c->cost_a = -((int)(a->length - c->pos_a));
	if (c->pos_b <= b->length / 2)
		c->cost_b = (int)c->pos_b;
	else
		c->cost_b = -((int)(b->length - c->pos_b));
}

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	total_cost(t_cost *c)
{
	int	ca;
	int	cb;

	ca = abs_val(c->cost_a);
	cb = abs_val(c->cost_b);
	if (c->cost_a > 0 && c->cost_b > 0)
		return (ca > cb) * ca + (ca <= cb) * cb;
	if (c->cost_a < 0 && c->cost_b < 0)
		return (ca > cb) * ca + (ca <= cb) * cb;
	return (ca + cb);
}

t_cost	find_cheapest(t_stack *a, t_stack *b)
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
		cur.pos_a = i;
		cur.pos_b = find_insert_pos_b(b, node->index);
		set_cost_directions(&cur, a, b);
		if (total_cost(&cur) < total_cost(&best))
			best = cur;
		node = node->next;
		i++;
	}
	return (best);
}

void	execute_rotations(t_stack *a, t_stack *b, t_op_list *ops, t_cost *c)
{
	while (c->cost_a > 0 && c->cost_b > 0)
	{
		rotate_both(a, b, ops);
		c->cost_a--;
		c->cost_b--;
	}
	while (c->cost_a < 0 && c->cost_b < 0)
	{
		reverse_rotate_both(a, b, ops);
		c->cost_a++;
		c->cost_b++;
	}
	while (c->cost_a > 0 && c->cost_a--)
		rotate(a, ops);
	while (c->cost_a < 0 && c->cost_a++)
		reverse_rotate(a, ops);
	while (c->cost_b > 0 && c->cost_b--)
		rotate(b, ops);
	while (c->cost_b < 0 && c->cost_b++)
		reverse_rotate(b, ops);
}
