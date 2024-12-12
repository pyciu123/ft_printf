/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:49 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:52:49 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int		i;
	int		j;
	char	*null;

	null = "(null)";
	i = 0;
	j = 0;
	if (!str)
	{
		while (null[j] != 0)
		{
			write(1, &null[j], 1);
			j++;
		}
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
