/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 13:35:49 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-13 13:35:49 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*verifie que la map est rectangulaire*/

void	width_checker(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->height)
	{
		if (ft_strlen(data->map[i - 1]) != ft_strlen(data->map[i]))
			error_manager(data, "Non-Rectangular Map\n", 1);
		i++;
	}
	return ;
}

/*Verifie le contenu de la map*/

void	char_checker(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (data ->map[i][j] != '\0')
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'C' && data->map[i][j] != '\n'
				&& data->map[i][j] != 'F')
				error_manager(data, "Invalid map content !\n", 1);
			j++;
		}
		i++;
	}
	return ;
}

/*verifie que la map est entourree par des murs*/

void	border_map_checker(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] != WALL && (i == 0 || i == (data->height) - 1))
				error_manager(data, "Invalid map borders !\n", 1);
			if (data->map[i][j] != WALL && (j == 0 || j == (data->width) - 1))
				error_manager(data, "Invalid map borders !\n", 1);
			j++;
		}
		i++;
	}
	return ;
}

/*Verifie le nombre correcte d'elements*/

void	element_checker(t_data *data)
{
	int	y;
	int	x;
	int	e_count;
	int	p_count;

	y = 0;
	e_count = 0;
	p_count = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == EXIT)
				e_count++;
			if (data->map[y][x] == PLAYER)
				p_count++;
			if (data->map[y][x] == COIN)
				data->tot_coin++;
			x++;
		}
		y++;
	}
	if (e_count != 1 || p_count != 1 || data->tot_coin < 1)
		error_manager(data, "Invalid number of elements !\n", 1);
}

/*Verifie la map*/

void	map_checker(t_data *data)
{
	width_checker(data);
	border_map_checker(data);
	element_checker(data);
	char_checker(data);
	find_pyx(data);
	connect_checker(data);
	ft_printf("Map successfully checked\n");
	return ;
}
