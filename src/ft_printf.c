/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:58 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:52:59 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	print_arg(va_list args, const char form)
{
	int	print_lenght;

	print_lenght = 0;
	if (form == 's')
		print_lenght += ft_print_str(va_arg(args, char *));
	else if (form == 'd' || form == 'i')
		print_lenght += ft_print_decimal(va_arg(args, int));
	else if (form == 'c')
		print_lenght += ft_printchar(va_arg(args, int));
	else if (form == 'p')
		print_lenght += ft_print_pointer(va_arg(args, unsigned long long));
	else if (form == 'u')
		print_lenght += ft_print_unsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		print_lenght += ft_print_hexadecimal
			((va_arg(args, unsigned int)), form);
	else if (form == '%')
		print_lenght += ft_print_percent();
	return (print_lenght);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lenght;
	va_list	args;

	i = 0;
	lenght = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			lenght += print_arg(args, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			lenght += 1;
		}
		i++;
	}
	va_end(args);
	return (lenght);
}
