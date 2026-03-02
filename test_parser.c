/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:39:07 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/02 18:16:01 by mberraho         ###   ########.fr       */
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

static void	clear_output(t_output_parsing **out)
{
	if (out)
		return ;
	if (*out)
	{
		if ((*out)->stack_a)
			free((*out)->stack_a);
		else
			free(*out);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_output_parsing	*output_parser;

	printf("argc is %d\n", argc);
	output_parser = run_parser(argc, argv);
	if (!output_parser)
		return (0);
	if (output_parser->bench_found)
		printf("bench is :%s\n", output_parser->bench_found);
	if (output_parser->option_found)
		printf("option is :%s\n", output_parser->option_found);
	if (output_parser->stack_a)
	{
		print_stack(output_parser->stack_a, "A");
		clear_stack(&output_parser->stack_a);
	}
	// print_stack(stack_a, "AFTER parsing");
	clear_output(&output_parser);
	return (0);
}
