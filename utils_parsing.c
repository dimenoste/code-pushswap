/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:36:33 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/06 13:49:10 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vars_ft_patols	init_vars_patol(void)
{
	t_vars_ft_patols	vars;

	vars.max = 2147483647;
	vars.i = 0;
	vars.n = 0;
	vars.sign = 1;
	return (vars);
}

int	is_digit_within_limits(char *s, t_vars_ft_patols vars)
{
	int	cond1;
	int	cond2;
	int	cond3;

	cond1 = (vars.n > (vars.max - (int)(s[vars.i] - '0')) / 10);
	cond2 = (vars.n > (vars.max + 1 - (int)(s[vars.i] - '0')) / 10);
	cond3 = (s[vars.i] < 48 || s[vars.i] > 57);
	return ((cond1 && vars.sign == 1) || (cond2 && vars.sign == -1) || cond3);
}

t_number	ft_patol(char *s)
{
	t_vars_ft_patols	vars;
	t_number			output;

	output.error = 1;
	output.number = 0;
	vars = init_vars_patol();
	if (s[vars.i] == '-')
	{
		vars.sign = -1;
		vars.i += 1;
	}
	while (s[vars.i] != '\0' && s[vars.i] != ' ')
	{
		if (is_digit_within_limits(s, vars))
		{
			return (output);
		}
		vars.n = vars.n * 10 + (int)(s[vars.i] - '0');
		vars.i++;
	}
	output.number = vars.sign * vars.n;
	output.error = 0;
	return (output);
}

int	ft_strcmp_space(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	j = ft_strlen(s2);
	while (s1[i] != '\0' || j != 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		j--;
	}
	return (1);
}
