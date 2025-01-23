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
		|| data->map[y][x] == WALL || data->map[y][x] == FOES || data->visit[y][x])
		return ;
	data->visit[y][x] = 1;
	dfs(data, y + 1, x);
	dfs(data, y - 1, x);
	dfs(data, y, x + 1);
	dfs(data, y, x - 1);
	return ;
}

void	imposible_map_checker(t_data *data, int i, int j)
{
	if ((data->map[i][j] == EXIT || data->map[i][j] == COIN)
				&& !data->visit[i][j])
	{
		free_array(data->visit, data->height);
		error_manager(data, "Impossible map\n", 1);
	}
}

void	connect_checker(t_data *data)
{
	int	i;
	int	j;
	int	y;
	int	x;

	y = data->p_y;
	x = data->p_x;
	i = 0;
	data->visit = malloc (data->height * sizeof(int **));
	while (i < data->height)
		data->visit[i++] = calloc(data->width, sizeof(int *));
	dfs(data, y, x);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			imposible_map_checker(data, i, j);
			j++;
		}
		i++;
	}
	free_array(data->visit, data->height);
	return ;
}
