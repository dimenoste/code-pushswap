/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:39:37 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/02 14:48:22 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    slow_radix_sort(t_stack *a, t_stack *b, t_op_list *out, int max_bits)
{
    int    bit;
    int    i;
    int    initial_size;

    bit = -1;
    while (++bit < max_bits)
    {
        i = -1;
        initial_size = a->length;
        while (++i < initial_size)
        {
            if (((a->head->value >> bit) & 1) == 0)
                push(a, b, out);
            else
                rotate(a, out);
        }
        while (b->length)
            push(b, a, out);
    }
}

void    radix_sort(t_stack *a, t_stack *b, t_op_list *out, int max_bits)
{
    int    bit;
    int    i;
    int    initial_size;

    bit = -1;
    while (++bit < max_bits)
    {
        i = -1;
        initial_size = a->length;
        while (++i < initial_size)
        {
            if (((a->head->index >> bit) & 1) == 0)
                push(a, b, out);
            else
                rotate(a, out);
        }
        while (b->length)
            push(b, a, out);
    }
}

int    find_max_bit(unsigned long value)
{
    int    size;

    size = 0;
    while (value)
    {
        size++;
        value = value >> 1;
    }
    return (size);
}

void	radix_sort_algo(t_stack *a, t_stack *b, t_op_list *ops)
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
	radix_sort(a, b, ops, find_max_bit(a->length - 1));
}
