/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_states1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:52:03 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/06 16:42:56 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_states	*init_states(void)
{
	t_states	*mystates;

	mystates = malloc(sizeof(t_states));
	if (!mystates)
		return (NULL);
	mystates->ptr_in_start_state = init_start_state();
	mystates->ptr_in_dash_state = init_dash_state();
	mystates->ptr_in_option_state = init_option_state();
	mystates->ptr_in_space_state = init_space_state();
	mystates->ptr_in_invalid_state = init_invalid_state();
	mystates->ptr_in_number_state = init_number_state();
	mystates->ptr_in_success_state = init_success_state();
	return (mystates);
}

t_state_interface	*init_start_state(void)
{
	t_state_interface	*ptr_in_start_state;

	ptr_in_start_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_start_state)
		return (NULL);
	ptr_in_start_state->handler_letter = &letter_when_in_start;
	ptr_in_start_state->handler_space = &space_when_in_start;
	ptr_in_start_state->handler_digit = &digit_when_in_start;
	ptr_in_start_state->handler_dash = &dash_when_in_start;
	ptr_in_start_state->handler_other = &other_when_in_start;
	ptr_in_start_state->handler_end = &end_when_in_start;
	return (ptr_in_start_state);
}

t_state_interface	*init_dash_state(void)
{
	t_state_interface	*ptr_in_dash_state;

	ptr_in_dash_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_dash_state)
		return (NULL);
	ptr_in_dash_state->handler_letter = &letter_when_in_dash;
	ptr_in_dash_state->handler_space = &space_when_in_dash;
	ptr_in_dash_state->handler_digit = &digit_when_in_dash;
	ptr_in_dash_state->handler_dash = &dash_when_in_dash;
	ptr_in_dash_state->handler_other = &other_when_in_dash;
	ptr_in_dash_state->handler_end = &end_when_in_dash;
	return (ptr_in_dash_state);
}

t_state_interface	*init_space_state(void)
{
	t_state_interface	*ptr_in_space_state;

	ptr_in_space_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_space_state)
		return (NULL);
	ptr_in_space_state->handler_letter = &letter_when_in_space;
	ptr_in_space_state->handler_space = &space_when_in_space;
	ptr_in_space_state->handler_digit = &digit_when_in_space;
	ptr_in_space_state->handler_dash = &dash_when_in_space;
	ptr_in_space_state->handler_other = &other_when_in_space;
	ptr_in_space_state->handler_end = &end_when_in_space;
	return (ptr_in_space_state);
}

t_state_interface	*init_number_state(void)
{
	t_state_interface	*ptr_in_number_state;

	ptr_in_number_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_number_state)
		return (NULL);
	ptr_in_number_state->handler_letter = &letter_when_in_number;
	ptr_in_number_state->handler_space = &space_when_in_number;
	ptr_in_number_state->handler_digit = &digit_when_in_number;
	ptr_in_number_state->handler_dash = &dash_when_in_number;
	ptr_in_number_state->handler_other = &other_when_in_number;
	ptr_in_number_state->handler_end = &end_when_in_number;
	return (ptr_in_number_state);
}
