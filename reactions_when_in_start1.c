/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInStart1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:52:48 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:19:43 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In Start
void	letter_when_in_start(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}

void	other_when_in_start(t_context *currState, t_states *mystates)
{
	letter_when_in_start(currState, mystates);
}

void	space_when_in_start(t_context *currState, t_states *mystates)
{
	toin_space_state(currState, mystates);
}
