/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 09:56:02 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-16 09:56:02 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_game(t_data	*data, int y, int x)
{
	if (data->map[y][x] == COIN)
	{
		data->play_coin++;
		data->map[y][x] = FLOOR;
	}
	else if (data->map[y][x] == EXIT && data->play_coin == data->tot_coin)
	{
		ft_printf ("\n\nYOU WIN !\n\n\n");
		close_game(data, 1);
	}
	else if (data->map[y][x] == FOES)
	{
		ft_printf ("\n\nYOU LOOSE !\n\n\n");
		close_game(data, 1);
	}
}

void	count_move(t_data *data)
{
	data->tot_move++;
	ft_printf("Total move : %d\n", data->tot_move);
	clear_count(data, 42, 42, 10, 10);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 35, 0x4F3818,ft_itoa(data->tot_move));
}

void	move_player(t_data *data, int y, int x)
{
	if (data->map[y][x] != WALL)
	{
		the_game(data, y, x);
		if (data->map[data->p_y][data->p_x] == EXIT
			&& data->play_coin != data->tot_coin)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data-> t_exit,
				data->p_x * TILE_SIZE, data->p_y * TILE_SIZE);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data-> t_floor, data->p_x * TILE_SIZE, data->p_y * TILE_SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data-> t_play_pos, x * TILE_SIZE, y * TILE_SIZE);
		data->p_x = x;
		data->p_y = y;
		count_move(data);
	}
}


int	moving(int keycode, t_data *data)
{
	int	y;
	int	x;

	y = data->p_y;
	x = data->p_x;
	if (keycode == ARROW_DOWN || keycode == KEY_S)
		move_player(data, y + 1, x);
	if (keycode == ARROW_UP || keycode == KEY_W)
		move_player(data, y - 1, x);
	if (keycode == ARROW_LEFT || keycode == KEY_A)
	{
		data->t_play_pos = data->t_play_left;
		move_player(data, y, x - 1);
	}
	if (keycode == ARROW_RIGHT || keycode == KEY_D)
	{
		data->t_play_pos = data->t_play_right;
		move_player(data, y, x + 1);
	}
	return (0);
}
