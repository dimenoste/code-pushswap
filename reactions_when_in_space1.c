/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInSpace1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:08 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:19:00 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In SpaceState
void	letter_when_in_space(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}

void	other_when_in_space(t_context *currState, t_states *mystates)
{
	toin_invalid_state(currState, mystates);
}

void	space_when_in_space(t_context *currState, t_states *mystates)
{
	toin_space_state(currState, mystates);
}
