/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:53:01 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/03/26 13:53:01 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h> 

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *str, ...);
int		ft_print_str(char *str);
int		ft_print_decimal(int n);
int		ft_printchar(int c);
int		ft_print_pointer(unsigned long long ptr);
char	*ft_unsigned_itoa(unsigned int n);
int		digit_count(unsigned int nb);
int		ft_print_unsigned(unsigned int num);
int		ft_print_hexadecimal(unsigned int num, const char format);
int		ft_print_percent(void);
void	ft_putchar_fd(char c, int fd);

#endif