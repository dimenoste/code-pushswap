/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benc_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:14:44 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 16:15:41 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_op(t_op_list *ops, t_op_type type)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < ops->count)
	{
		if (ops->operations[i] == type)
			count++;
		i++;
	}
	return (count);
}

void	write_int_fd(int fd, int n)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		write_int_fd(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	write_disorder_fd(int fd, float disorder)
{
	int	percent;

	percent = (int)(disorder * 10000);
	write_int_fd(fd, percent / 100);
	write(fd, ".", 1);
	if ((percent % 100) < 10)
		write(fd, "0", 1);
	write_int_fd(fd, percent % 100);
}
