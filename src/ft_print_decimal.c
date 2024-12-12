/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:40 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:52:41 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_print_decimal(int n)
{
	char	*number;
	int		length;
	int		i;

	i = 0;
	number = ft_itoa(n);
	length = ft_strlen(number);
	while (number[i] != 0)
	{
		write(1, &number[i], 1);
		i++;
	}
	free(number);
	return (length);
}
