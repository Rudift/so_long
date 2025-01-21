/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 09:03:23 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-15 09:03:23 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_data *data)
{
	if (data->t_wall)
		mlx_destroy_image(data->mlx_ptr, data->t_wall);
	if (data->t_floor)
		mlx_destroy_image(data->mlx_ptr, data->t_floor);
	if (data->t_player)
		mlx_destroy_image(data->mlx_ptr, data->t_player);
	if (data->t_coin)
		mlx_destroy_image(data->mlx_ptr, data->t_coin);
	if (data->t_exit)
		mlx_destroy_image(data->mlx_ptr, data->t_exit);
}

void	load_textures(t_data *data)
{

	int	width = TILE_SIZE;
	int	height = TILE_SIZE;
	
	data->t_wall = mlx_xpm_file_to_image(data->mlx_ptr, "./srcs/textures/wall.xpm", &width, &height);
	data->t_floor = mlx_xpm_file_to_image(data->mlx_ptr, "./srcs/textures/floor.xpm", &width, &height);
	data->t_coin = mlx_xpm_file_to_image(data->mlx_ptr, "./srcs/textures/tresure.xpm", &width, &height);
	data->t_player = mlx_xpm_file_to_image(data->mlx_ptr, "./srcs/textures/elf_1.xpm", &width, &height);
	data->t_exit = mlx_xpm_file_to_image(data->mlx_ptr, "./srcs/textures/exit.xpm", &width, &height);
	if (!data->t_wall || !data->t_floor || !data->t_exit || !data->t_coin || !data->t_player)
		error_manager(data, "Textures loading error !\n", 2);
	return ;
}

void	render_map(t_data *data)
{
	int		y;
	int		x;
	void	*img;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			img = NULL;
			if(data->map[y][x] == WALL)
				img = data->t_wall;
			else if(data->map[y][x] == FLOOR)
				img = data->t_floor;
			else if(data->map[y][x] == COIN)
				img = data->t_coin;
			else if(data->map[y][x] == PLAYER)
				img = data->t_player;
			else if(data->map[y][x] == EXIT)
				img = data->t_exit;
			if(img)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
