/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInNumber2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:38:54 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/02 18:02:43 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_number(t_context *currState, t_states *mystates)
{
	toin_number_state(currState, mystates);
}

void	dash_when_in_number(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}

void	space_when_in_number(t_context *currState, t_states *mystates)
{
	t_number	result;
	int			is_number_unique;

	is_number_unique = 0;
	result = ft_patol(currState->start_number);
	if (result.error == 0)
	{
		currState->candidate_number = result.number;
		is_number_unique = is_node_unique(currState->stack_a,
				new_node(result.number));
		toin_space_state(currState, mystates);
	}
	else if (result.error != 0 || is_number_unique == 0)
	{
		toin_invalid_state(currState, mystates);
	}
}

void	end_when_in_number(t_context *currState, t_states *mystates)
{
	t_number	result;
	int			is_number_unique;

	is_number_unique = 0;
	result = ft_patol(currState->start_number);
	if (result.error == 0)
	{
		currState->candidate_number = result.number;
		to_end_success(currState, mystates);
		is_number_unique = is_node_unique(currState->stack_a,
				new_node(result.number));
	}
	if (result.error != 0 || is_number_unique == 0)
	{
		toin_invalid_state(currState, mystates);
	}
}
