/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:42 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:52:43 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_digit(unsigned int digit, int *length, const char format)
{
	length += 0;
	if (digit < 10)
	{
		ft_putchar_fd((digit + '0'), 1);
		(*length)++;
	}
	else if (format == 'x')
	{
		ft_putchar_fd((digit - 10 + 'a'), 1);
		(*length)++;
	}
	else if (format == 'X')
	{
		ft_putchar_fd((digit - 10 + 'A'), 1);
		(*length)++;
	}
}

void	ft_decimal_to_hex(unsigned int number, int *length, const char format)
{
	if (number / 16)
	{
		ft_decimal_to_hex((number / 16), length, format);
	}
	ft_print_hex_digit((number % 16), length, format);
}

int	ft_print_hexadecimal(unsigned int num, const char format)
{
	int	length;

	length = 0;
	ft_decimal_to_hex(num, &length, format);
	return (length);
}
