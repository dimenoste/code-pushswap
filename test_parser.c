/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 19:04:55 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_current_state(t_output_parsing *output)
{
	printf("====== CURR STATE ===============\n");
	printf("current state of string is : %s\n",
		get_state_name(output->name_state));
	if (output->option_found)
		printf("option  found is : %s\n", output->option_found);
	else
		printf("option  not found \n");
	if (output->bench_found)
		printf("bench  found is : %s\n", output->bench_found);
	else
		printf("bench  not found \n");
	print_stack(output->stack_a, "stack from parsing");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_output_parsing	*output_parser;


	printf("argc is %d\n", argc);
	output_parser = run_parser(argc, argv);

	
	print_stack(output_parser->stack_a, "A");
	if (!output_parser->bench_found)
		printf("bench is %s\n", output_parser->bench_found);
	if (!output_parser->bench_found)
		printf("option is %s\n", output_parser->option_found);
	// print_stack(stack_a, "AFTER parsing");
	free(output_parser);
	clear_stack(&stack_a);
	return (0);
}
