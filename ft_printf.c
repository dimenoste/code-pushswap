/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:16:49 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/06 16:52:38 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handler(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_put_hexa(va_arg(args, unsigned int), 0));
	else if (spec == 'X')
		return (ft_put_hexa(va_arg(args, unsigned int), 1));
	else if (spec == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (spec == 'l')
		return (ft_putnbr_l(va_arg(args, long)));
	else if (spec == 'u')
		return (ft_putnbr_zu(va_arg(args, size_t)));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handler(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
