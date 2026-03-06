/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:43:17 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/06 19:06:44 by mberraho         ###   ########.fr       */
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
