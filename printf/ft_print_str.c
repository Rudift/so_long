/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:00:05 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/22 16:35:04 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		count += ft_print_str("(null)");
	else
	{
		while (*str)
		{
			ft_print_char((int)*str);
			++count;
			++str;
		}
	}
	return (count);
}
