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

int	main(int argc, char *argv[])
{
	t_output_parsing	*output_parser;

	output_parser = run_parser(argc, argv);
	if (!output_parser)
		return (0);
	if (output_parser->stack_a)
	{
		run_strategy(output_parser);
	}
	clear_output(&output_parser);
	return (0);
}
