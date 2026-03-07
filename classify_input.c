/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:56:46 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:12:48 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	classify_input(t_context *curr_state, t_states *mystates)
{
	char	input;

	input = *(curr_state->mystring);
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		return (curr_state->interface->handler_letter(curr_state, mystates));
	else if (input >= '0' && input <= '9')
	{
		if (curr_state->nber_digits == 0)
			curr_state->start_number = curr_state->mystring;
		return (curr_state->interface->handler_digit(curr_state, mystates));
	}
	else if (input == ' ')
		return (curr_state->interface->handler_space(curr_state, mystates));
	else if (input == '-')
	{
		if (curr_state->nber_dash == 0 && curr_state->name_state != InOption)
			curr_state->addr_first_dash = curr_state->mystring;
		return (curr_state->interface->handler_dash(curr_state, mystates));
	}
	else if (input == '\0')
		return (curr_state->interface->handler_end(curr_state, mystates));
	else
		return (curr_state->interface->handler_other(curr_state, mystates));
}
