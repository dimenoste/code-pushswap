/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInOption1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:43 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:18:27 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In OptionState
void	letter_when_in_option(t_context *currState, t_states *mystates)
{
	toin_option_state(currState, mystates);
}

void	other_when_in_option(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}

void	space_when_in_option(t_context *currState, t_states *mystates)
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
	{
		toin_space_state(currState, mystates);
	}
}
