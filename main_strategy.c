/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:49:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/06 13:55:45 by yasmine.aichi    ###   ########.fr       */
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
int	main(int argc, char *argv[])
{
	t_output_parsing *output_parser;

	//printf("argc is %d\n", argc);
	output_parser = run_parser(argc, argv);
	if (!output_parser)
		return (0);
	//if (output_parser->bench_found)
		//printf("bench is : |%s|\n", output_parser->bench_found);
	//if (output_parser->option_found)
		//printf("option is : |%s|\n", output_parser->option_found);
	if (output_parser->stack_a)
	{
		print_stack(output_parser->stack_a, "A");
		run_strategy(output_parser);
		print_stack(output_parser->stack_a, "AFTER parsing");
	}
	// print_stack(stack_a, "AFTER parsing");

	clear_output(&output_parser);
	return (0);
}
