/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:17:23 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/22 16:33:12 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (spec == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (spec == 'p')
		count += ft_print_pnt(va_arg(args, void *));
	else if (spec == 'x')
		count += ft_print_hexa((unsigned long)va_arg(args, unsigned int), 'x');
	else if (spec == 'X')
		count += ft_print_hexa((unsigned long)va_arg(args, unsigned int), 'X');
	else if (spec == 'd' || spec == 'i')
		count += ft_print_digit(va_arg(args, int));
	else if (spec == 'u')
		count += ft_print_unsign((unsigned int)va_arg(args, int));
	else if (spec == '%')
		count += write (1, "%", 1);
	else
		count += write(1, &spec, 1);
	return (count);
}
