/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 10:12:05 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-14 10:12:05 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pyx(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				data->p_y = y;
				data->p_x = x;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	dfs(t_data *data, int y, int x)
{
	if (y < 0 || x < 0 || y >= data->height || x >= data->width 
		|| data->map[y][x] == WALL || data->visit[y][x])
		return ;
	data->visit[y][x] = 1;
	dfs(data, y + 1, x);
	dfs(data, y - 1, x);
	dfs(data, y, x + 1);
	dfs(data, y, x - 1);
	return ;
}

void	connect_checker(t_data *data)
{
	int	i;
	int	j;
	int y = data->p_y;
	int x = data->p_x;

	i = 0;
	data->visit = malloc (data->height * sizeof(int *));
	while (i < data->height)
	{
		data->visit[i] = calloc(data->width, sizeof(int));
		i++;
	}
	dfs(data, y, x);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if((data->map[i][j] == EXIT || data->map[i][j] == COIN) && !data->visit[i][j])
			{
				ft_printf("Error\n");
				error_manager(data, "Impossible map\n", 1);
			}
			j++;
		}
		i++;
	}
	return ;
}