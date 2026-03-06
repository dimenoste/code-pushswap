/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:52:26 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 17:37:27 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("number at index %d is %d\n", i, arr[i]);
		i++;
	}
}

int	*init_array(int *arr, int len, int val)
{
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = val;
		i++;
	}
	return (arr);
}
