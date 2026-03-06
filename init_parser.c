/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:41:38 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/06 17:08:22 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_parser_arg(t_states *mystates, t_context *ptr_parser, char *s,
		t_stack *stk)
{
	ptr_parser->interface = mystates->ptr_in_start_state;
	ptr_parser->name_state = InStart;
	ptr_parser->mystring = s;
	ptr_parser->addr_first_dash = NULL;
	ptr_parser->bench_found = NULL;
	ptr_parser->nber_dash = 0;
	ptr_parser->nber_digits = 0;
	ptr_parser->start_number = NULL;
	ptr_parser->option_found = NULL;
	ptr_parser->stack_a = stk;
}

t_output_parsing	*init_output_parser(void)
{
	t_output_parsing	*output;
	t_stack				*stk;

	output = malloc(sizeof(t_output_parsing));
	if (!output)
		return (NULL);
	stk = new_stack(A);
	output->name_state = InInvalid;
	output->option_found = NULL;
	output->bench_found = NULL;
	output->stack_a = stk;
	return (output);
}

void	clear_output(t_output_parsing **out)
{
	if (!out)
		return ;
	else if (*out)
	{
		clear_stack(&((*out)->stack_a));
		free(*out);
		return ;
	}
	return ;
}
