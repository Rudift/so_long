/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:16 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/22 16:40:13 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(int nb)
{
	int		count;
	char	*dectab;

	count = 0;
	dectab = "0123456789";
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_print_digit(nb / 10);
		count += ft_print_char(dectab[nb % 10]);
	}
	else
		count += ft_print_char(dectab[nb]);
	return (count);
}
