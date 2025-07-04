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

/*Initialisation de la structure data*/

void	data_init2(t_data *data, char *path)
{
	data->t_exit = NULL;
	data->visit = NULL;
	data->tot_coin = 0;
	data->play_coin = 0;
	data->tot_move = 0;
	data->timer_iddle = 0;
	data->end = 0;
	map_init(data, path);
	map_checker(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_manager(data, "Mlx initialization error !\n", 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, ((data->width) * TILE_SIZE),
			((data->height) * TILE_SIZE), "test");
}

void	data_init(t_data *data, char *path)
{
	data->height = 0;
	data->width = 0;
	data->p_y = 0;
	data->p_x = 0;
	data->t_wall = NULL;
	data->t_floor = NULL;
	data->t_play_pos = NULL;
	data->t_play_left1 = NULL;
	data->t_play_left2 = NULL;
	data->t_play_right1 = NULL;
	data->t_play_right2 = NULL;
	data->t_foes_pos = NULL;
	data->t_foes1 = NULL;
	data->t_foes2 = NULL;
	data->t_coin = NULL;
	data_init2(data, path);
}
