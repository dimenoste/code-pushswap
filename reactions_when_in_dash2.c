/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInDash2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:42:22 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:29:50 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_dash(t_context *currState, t_states *mystates)
{
	if (currState->nber_dash == 1)
	{
		currState->start_number = currState->addr_first_dash;
		toin_number_state(currState, mystates);
		currState->nber_dash = 0;
	}
	else if (currState->nber_dash == 0)
	{
		currState->start_number = currState->start_number;
		toin_number_state(currState, mystates);
		currState->nber_dash = 0;
	}
	else
		toin_invalid_state(currState, mystates);
}
// reset dash counter to 0

void	dash_when_in_dash(t_context *currState, t_states *mystates)
{
	if (currState->nber_dash < 2)
	{
		toin_dash_state(currState, mystates);
	}
	else
		toin_invalid_state(currState, mystates);
}

void	end_when_in_dash(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}
