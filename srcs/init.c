/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 08:42:32 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-10 08:42:32 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_data *data, char *path)
{
	data->height = 0;
	data->width = 0;
	data->p_y = 0;
	data->p_x = 0;
	data->t_wall = NULL;
	data->t_floor = NULL;
	data->t_player = NULL;
	data->t_coin = NULL;
	data->t_exit = NULL;
	data->visit = NULL;
	data->tot_coin = 0;
	data->play_coin = 0;
	data->tot_move = 0;
	map_init(data, path);
	map_checker(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, ((data->width) * TILE_SIZE),
			((data->height) * TILE_SIZE), "test");
}
