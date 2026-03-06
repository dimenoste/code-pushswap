/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInOption2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:45:28 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 19:27:50 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_option(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}

void	dash_when_in_option(t_context *currState, t_states *mystates)
{
	if (currState->nber_dash != 2)
		toin_invalid_state(currState, mystates);
	else
		toin_dash_state(currState, mystates);
}

void	end_when_in_option(t_context *currState, t_states *mystates)
{
	int	is_option_found;
	int	is_bench_found;

	is_option_found = -1;
	is_bench_found = -1;
	is_option_found = extract_option_in_state(currState);
	is_bench_found = extract_bench_in_state(currState);
	if (is_option_found == 0 && is_bench_found == 0)
	{
		toin_invalid_state(currState, mystates);
	}
	else
		to_end_success(currState, mystates);
}
