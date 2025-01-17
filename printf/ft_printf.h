/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:43:04 by vdeliere          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:49 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

/*Principale*/
int	ft_printf(const char *format, ...);
/*Fonction de triage*/
int	ft_print_format(char spec, va_list args);
/*Fonctions specs*/
int	ft_print_digit(int nb);
int	ft_print_unsign(unsigned int nb);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_hexa(unsigned long nb, char spec);
int	ft_print_pnt(void *pnt);
#endif
