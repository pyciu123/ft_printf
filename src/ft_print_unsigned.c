/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:52 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:52:53 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int		lenght;
	char	*result;
	int		i;

	i = 0;
	lenght = digit_count(num);
	result = ft_unsigned_itoa(num);
	while (result[i] != 0)
	{
		write(1, &result[i], 1);
		i++;
	}
	free(result);
	return (lenght);
}
