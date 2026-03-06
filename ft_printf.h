/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:18:57 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/28 03:02:24 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	myprintf(const char *format, ...);
int	ft_putchar(char c);
int	ft_strlen(char *str);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned long nb);
int	ft_putnbr_l(long nb);
int	ft_putnbr_zu(size_t nb);
int	ft_put_hexa(unsigned long long nb, int case_arg);
int	ft_ptr(void *ptr);

#endif
