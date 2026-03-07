/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:32:30 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/28 03:03:13 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_strat_selector(char *s)
{
	int		i;
	char	*strats[5];

	strats[0] = "--simple";
	strats[1] = "--medium";
	strats[2] = "--complex";
	strats[3] = "--adaptive";
	strats[4] = NULL;
	i = 0;
	while (strats[i])
	{
		if (ft_strcmp_space(s, strats[i]) == 1)
		{
			return (strats[i]);
		}
		i++;
	}
	return (NULL);
}

char	*get_bench_selector(char *s)
{
	char	*bench;
	char	*cc;

	bench = "--bench";
	cc = "--count-only";
	if (ft_strcmp_space(s, bench) == 1)
	{
		return (bench);
	}
	else if (ft_strcmp_space(s, cc) == 1)
	{
		return (cc);
	}
	return (NULL);
}

const char	*get_state_name(t_enum_state_name enum_name)
{
	const char	*states_names[8];

	states_names[0] = "in_start_state";
	states_names[1] = "in_dash_state";
	states_names[2] = "in_option_state";
	states_names[3] = "in_space_state";
	states_names[4] = "in_invalid_state";
	states_names[5] = "in_number_state";
	states_names[6] = "in_success_state";
	states_names[7] = NULL;
	return (states_names[enum_name]);
}
