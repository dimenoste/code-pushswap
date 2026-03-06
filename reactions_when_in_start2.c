/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_when_in_start2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:52:37 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:20:05 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_when_in_start(t_context *currState, t_states *mystates)
{
	toin_number_state(currState, mystates);
}

void	dash_when_in_start(t_context *currState, t_states *mystates)
{
	toin_dash_state(currState, mystates);
}

void	end_when_in_start(t_context *currState, t_states *mystates)
{
	to_end_success(currState, mystates);
}
