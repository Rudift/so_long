/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:42:17 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/22 16:19:19 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long nb, char spec)
{
	int		count;
	char	*hextab;

	count = 0;
	if (spec == 'X')
		hextab = "0123456789ABCDEF";
	else
		hextab = "0123456789abcdef";
	if (nb < 16)
		count += ft_print_char(hextab[nb]);
	else
	{
		count += ft_print_hexa(nb / 16, spec);
		count += ft_print_char(hextab[nb % 16]);
	}
	return (count);
}
