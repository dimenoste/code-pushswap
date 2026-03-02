/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:24:59 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 19:04:21 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_output_parsing	*init_output_parser(void)
{
	t_output_parsing	*output;
	t_stack				*stk;

	output = malloc(sizeof(t_output_parsing));
	if (!output)
	{
		
		return (NULL);
	}
	printf("alloc ok !!!\n");	
	stk = new_stack(A);
	output->name_state = InInvalid;
	output->option_found = NULL;
	output->bench_found = NULL;
	output->stack_a = stk;
	return (output);
}

void	update_output_parser(t_context *ptr_parser, t_output_parsing *output)
{
	output->name_state = ptr_parser->name_state;
	if (!output->option_found && ptr_parser->option_found)
		output->option_found = ptr_parser->option_found;
	if (!output->bench_found && ptr_parser->bench_found)
		output->bench_found = ptr_parser->bench_found;
	output->stack_a = ptr_parser->stack_a;
}

int	validate_args_inner_loop(int i, t_vars_pars_loop *vars, int argc,
		char *argv[])
{
	while (i < argc)
	{
		init_parser_arg(vars->mystates, vars->ptr_parser, argv[i],
			vars->output->stack_a);
		while (1)
		{
			classify_input(vars->ptr_parser, vars->mystates);
			update_output_parser(vars->ptr_parser, vars->output);
			if (vars->output->name_state == InInvalid)
			{
				write(1, "Error\n", 6);
				clear_stack(&(vars->output->stack_a));
				free(vars->ptr_parser);
				free_mystates(vars->mystates);
				return (0);
			}
			else if (vars->ptr_parser->name_state == InSuccess)
				break ;
			(vars->ptr_parser->mystring)++;
		}
		i++;
	}
	free(vars->ptr_parser);
	free_mystates(vars->mystates);
	return (1);
}

int	validate_args(int argc, char *argv[], t_output_parsing *output)
{
	t_vars_pars_loop	*pvars;
	t_vars_pars_loop	vars;
	int					i;

	i = 1;
	pvars = &vars;
	pvars->mystates = init_states();
	pvars->ptr_parser = malloc(sizeof(t_context));
	pvars->output = output;
	if (!pvars->ptr_parser || !pvars->mystates)
		return (0);
	return (validate_args_inner_loop(i, pvars, argc, argv));
}

t_output_parsing	*run_parser(int argc, char *argv[])
{
	t_output_parsing	*output;
	int					is_args_valid;


	printf("from run_parser : argc is %d\n", argc);
	
	if (argc == 3){
			printf("on est dedans : argc is %d\n", argc);

	output = init_output_parser();
	is_args_valid = validate_args(argc, argv, output);
	if (is_args_valid != 1)
		return (NULL);
	if (output->name_state == InInvalid)
	{
		return (NULL);
	}
	if (is_empty_stack(output->stack_a) || is_in_order(output->stack_a))
	{
		clear_stack(&(output->stack_a));
		return (NULL);
	}
	printf("\n");
	}
	return (output);
}
