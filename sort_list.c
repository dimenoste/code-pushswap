/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:43:17 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 17:13:11 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_temp(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble(int *arr, int len)
{
	int	end_idx;
	int	i;

	if (!arr || len < 2)
	{
		return ;
	}
	end_idx = len - 1;
	while (end_idx > 0)
	{
		i = 0;
		while (i < end_idx)
		{
			if (arr[i] > arr[i + 1])
			{
				swap_temp(&arr[i], &arr[i + 1]);
			}
			i++;
		}
		end_idx--;
	}
}

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
	myprintf("==============================================\n");
	while (i < len)
	{
		myprintf("number at index %d is %d\n", i, arr[i]);
		i++;
	}
	printf("==============================================\n");
}
/*
insertion_sort_helperst	main(void)
{
	int	arr[] = {8, 3, 4, 6, 5,
		2, 0, 7, 9, 1};

	print_array(arr, 10);
	bubble(arr, 10);
	print_array(arr, 10);
	return (0);
}
*/
