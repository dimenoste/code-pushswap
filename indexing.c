/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:20:11 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/04 19:20:18 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_array(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_rank(int *sorted, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*copy_values(t_stack *stk)
{
	int		*arr;
	t_node	*cur;
	size_t	i;

	arr = malloc(sizeof(int) * stk->length);
	if (!arr)
		return (NULL);
	cur = stk->head;
	i = 0;
	while (i < stk->length)
	{
		arr[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (arr);
}

void	assign_indices(t_stack *stk)
{
	int		*sorted;
	t_node	*cur;
	size_t	i;

	if (!stk || stk->length == 0)
		return ;
	sorted = copy_values(stk);
	if (!sorted)
		return ;
	sort_int_array(sorted, (int)stk->length);
	cur = stk->head;
	i = 0;
	while (i < stk->length)
	{
		cur->index = find_rank(sorted, (int)stk->length, cur->value);
		cur = cur->next;
		i++;
	}
	free(sorted);
}
