/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:50:52 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 13:52:42 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble(int *arr, int len)
{
	int	i;

	i = 0;
	if (!arr || len < 2)
		return ;
	while (len > 0)
	{
		i = 0;
		while (i < (len - 1))
		{
			if (arr[i] > arr[i + 1])
			{
				swap_array(&arr[i], &arr[i + 1]);
			}
			i++;
		}
		len--;
	}
}

size_t	find_index(int val, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (val == arr[i])
			return (i);
		i++;
	}
	return (i);
}

void	add_index_node(t_stack *stk)
{
	t_node	*ptr_node;
	size_t	i;
	size_t	index;
	int		*arr_sorted;

	i = 0;
	if (!stk || stk->length < 2)
		return ;
	arr_sorted = copy_values(stk);
	bubble(arr_sorted, stk->length);
	ptr_node = stk->head;
	while (i < stk->length)
	{
		index = find_index(ptr_node->value, arr_sorted, stk->length);
		ptr_node->index = index;
		ptr_node = ptr_node->next;
		i++;
	}
	free(arr_sorted);
}
