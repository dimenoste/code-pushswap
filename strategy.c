/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:21:14 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/04 19:09:16 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"
#include "push_swap.h"

t_op_list	*run_algo_simple(t_stack *stk)
{
	t_stack		*b;
	t_op_list	*ops;

	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(stk, b, ops);
	clear_stack(&b);
	return (ops);
}
t_op_list	*run_algo_medium(t_stack *stk)
{
	t_stack		*b;
	t_op_list	*ops;

	// algo_medium(stk);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(stk, b, ops);
	clear_stack(&b);
	return (ops);
}

t_op_list	*run_algo_complex(t_stack *stk)
{

	t_stack		*b;
	t_op_list	*ops;

	// algo_medium(stk);
	// algo_medium(stk);
	b = new_stack(B);
	ops = new_op_list();
	radix_sort_algo(stk, b, ops);

	clear_stack(&b);
	return (ops);
}

t_op_list	*run_algo_adaptive(t_stack *stk)
{
	float		disorder;
	t_op_list	*ops;

	disorder = compute_disorder(stk);
	if (disorder > 2)
		ops = run_algo_simple(stk);
	else if (0.2 <= disorder && disorder < 0.5)
		ops = run_algo_medium(stk);
	else
		ops = run_algo_complex(stk);
	return (ops);
 }

void	run_strategy(t_output_parsing *output_parser)
{
	char		*strat;
	t_op_list	*ops;
	float disorder;
	disorder = compute_disorder(output_parser->stack_a);
	if (!output_parser || !output_parser->stack_a)
		return ;
	strat = output_parser->option_found;
	if (ft_strcmp_space(strat, "--simple"))
		ops = run_algo_simple(output_parser->stack_a);
//	else if (ft_strcmp_space(strat, "--medium"))
	//	ops = run_algo_medium(output_parser->stack_a);
	else if (ft_strcmp_space(strat, "--complex"))
		ops = run_algo_complex(output_parser->stack_a);
	else if (ft_strcmp_space(strat, "--adaptive") || !strat)
		ops = run_algo_adaptive(output_parser->stack_a);
	if (ops)
	{
		//printf("  operations list:\n  ");
		//print_operations(ops);
	}
	if (output_parser->bench_found)
	{
	display_bench(ops, strat, disorder);
	}
	// clear_op_list(&ops);
}
