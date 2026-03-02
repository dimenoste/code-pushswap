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
//int main()
//{
// (...)
// Works because with indexed values, we are bound by the highest possible value in our list - which is the highest index, e.g size-1
  //  if (input->complex)
    //    radix_sort(main_stack, b_stack, out, find_max_bit((main_stack)->size - 1));
// (...)
//}

