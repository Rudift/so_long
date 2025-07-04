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

/*Detruit les images existante*/

void	destroy_images(t_data *data)
{
	if (data->t_coin)
		mlx_destroy_image(data->mlx_ptr, data->t_coin);
	if (data->t_exit)
		mlx_destroy_image(data->mlx_ptr, data->t_exit);
	if (data->t_wall)
		mlx_destroy_image(data->mlx_ptr, data->t_wall);
	if (data->t_floor)
		mlx_destroy_image(data->mlx_ptr, data->t_floor);
	if (data->t_play_left1)
		mlx_destroy_image(data->mlx_ptr, data->t_play_left1);
	if (data->t_play_left2)
		mlx_destroy_image(data->mlx_ptr, data->t_play_left2);
	if (data->t_play_right1)
		mlx_destroy_image(data->mlx_ptr, data->t_play_right1);
	if (data->t_play_right2)
		mlx_destroy_image(data->mlx_ptr, data->t_play_right2);
	if (data->t_foes1)
		mlx_destroy_image(data->mlx_ptr, data->t_foes1);
	if (data->t_foes2)
		mlx_destroy_image(data->mlx_ptr, data->t_foes2);
}

/*Deuxieme partie du chargement des textures*/

void	load_textures2(t_data *data, int width, int height)
{	
	data->t_foes1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/skeleton.xpm", &width, &height);
	data->t_foes2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/skeleton2.xpm", &width, &height);
	data->t_play_pos = data->t_play_right1;
	data->t_foes_pos = data->t_foes1;
	if (!data->t_wall || !data->t_floor || !data->t_exit
		|| !data->t_coin || !data->t_play_left1 || !data->t_play_left2
		|| !data->t_play_right1 || !data->t_play_right2 || !data->t_foes1
		|| !data->t_foes2)
		error_manager(data, "Textures loading error !\n", 2);
}

/*Chargement des textures dans la structure*/

void	load_textures(t_data *data)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	data->t_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/wall.xpm", &width, &height);
	data->t_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/floor.xpm", &width, &height);
	data->t_coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/tresure.xpm", &width, &height);
	data->t_play_left1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/play_left_1.xpm", &width, &height);
	data->t_play_right1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/play_right_1.xpm", &width, &height);
	data->t_play_left2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/play_left_2.xpm", &width, &height);
	data->t_play_right2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/play_right_2.xpm", &width, &height);
	data->t_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./srcs/textures/exit.xpm", &width, &height);
	load_textures2(data, width, height);
}

/*Affichage d'image en fonction de data->map[y][x]*/

void	img_assign(t_data *data, void *img, int x, int y)
{
	if (data->map[y][x] == FLOOR || data->map[y][x] == PLAYER)
		img = data->t_floor;
	else if (data->map[y][x] == WALL)
		img = data->t_wall;
	else if (data->map[y][x] == COIN)
		img = data->t_coin;
	if (y == data->p_y && x == data->p_x)
		img = data->t_play_pos;
	else if (data->map[y][x] == EXIT)
		img = data->t_exit;
	else if (data->map[y][x] == FOES)
		img = data->t_foes_pos;
	if (img)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
	if (y == data->p_y && x == data->p_x)
	{
		img = data->t_play_pos;
	}
	if (img)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

/*Boucle pour parcourir la map*/
/*Appelle img_assign pour chaque coordonnees de la map*/

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
			img_assign(data, img, x, y);
			x++;
		}
		y++;
	}
}
