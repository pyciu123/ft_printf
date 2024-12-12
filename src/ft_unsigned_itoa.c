/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:53:04 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:53:04 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digit_count(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i = 1;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	writenum(unsigned int nb, char *result, int *i)
{
	if (nb >= 10)
	{
		writenum(nb / 10, result, i);
		writenum(nb % 10, result, i);
	}
	else
	{
		result[(*i)++] = nb + '0';
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*result;
	int		i;

	result = malloc((digit_count(n) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	writenum(n, result, &i);
	result[i] = '\0';
	return (result);
}
