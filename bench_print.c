/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:32:34 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/04 19:14:26 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"
#include "ft_stack.h"
#include "push_swap.h"

static size_t	count_op(t_op_list *ops, t_op_type type)
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

static void	write_int_fd(int fd, int n)
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

static void	write_disorder_fd(int fd, float disorder)
{
	int	percent;

	percent = (int)(disorder * 10000);
	write_int_fd(fd, percent / 100);
	write(fd, ".", 1);
	if ((percent % 100) < 10)
		write(fd, "0", 1);
	write_int_fd(fd, percent % 100);
}

static void	bench_strategy_info(char *strat)
{
	if (!strat || ft_strcmp_space(strat, "--adaptive"))
		write(2, "Adaptive / O(n*sqrt(n))", 23);
	else if (ft_strcmp_space(strat, "--simple"))
		write(2, "Simple / O(n^2)", 15);
	else if (ft_strcmp_space(strat, "--medium"))
		write(2, "Medium / O(n*sqrt(n))", 21);
	else if (ft_strcmp_space(strat, "--complex"))
		write(2, "Complex / O(n log n)", 20);
	else
		write(2, "Unknown", 7);
}

void	print_bench_ops(t_op_list *ops)
{
	write(2, "\n[bench] sa: ", 13);
	write_int_fd(2, (int)count_op(ops, OP_SA));
	write(2, " sb: ", 5);
	write_int_fd(2, (int)count_op(ops, OP_SB));
	write(2, " ss: ", 5);
	write_int_fd(2, (int)count_op(ops, OP_SS));
	write(2, " pa: ", 5);
	write_int_fd(2, (int)count_op(ops, OP_PA));
	write(2, " pb: ", 5);
	write_int_fd(2, (int)count_op(ops, OP_PB));
	write(2, "\n[bench] ra: ", 13);
	write_int_fd(2, (int)count_op(ops, OP_RA));
	write(2, " rb: ", 5);
	write_int_fd(2, (int)count_op(ops, OP_RB));
	write(2, " rr: ", 5);
	write_int_fd(2, (int)count_op(ops, OP_RR));
	write(2, " rra: ", 6);
	write_int_fd(2, (int)count_op(ops, OP_RRA));
	write(2, " rrb: ", 6);
	write_int_fd(2, (int)count_op(ops, OP_RRB));
	write(2, " rrr: ", 6);
	write_int_fd(2, (int)count_op(ops, OP_RRR));
	write(2, "\n", 1);
}
void	display_bench(t_op_list *ops, char *strategy, float disorder)
{
	if (!ops)
		return ;
	write(2, "[bench] disorder: ", 18);
	write_disorder_fd(2, disorder);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	bench_strategy_info(strategy);
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	write_int_fd(2, (int)ops->count);
	print_bench_ops(ops);
}
