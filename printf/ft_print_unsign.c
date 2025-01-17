/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:47:15 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/22 16:17:48 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsign(unsigned int nb)
{
	int		count;
	char	*dectab;

	count = 0;
	dectab = "0123456789";
	if (nb > 9)
	{
		count += ft_print_unsign(nb / 10);
		count += ft_print_char(dectab[nb % 10]);
	}
	else
		count += ft_print_char(dectab[nb]);
	return (count);
}
