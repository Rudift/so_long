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

void	move_player(t_data *data, int y, int x)
{
	if (data->map[y][x] != WALL)
		{
			if (data->map[y][x] == COIN)
			{
				data->play_coin++;
				data->map[y][x] = FLOOR;
			}
			else if (data->map[y][x] == EXIT && data->play_coin == data->tot_coin)
			{
				ft_printf ("YOU WIN FILTHY MF !\n");
				//faire fonction qui quite le jeu proprement
			}
			ft_printf("Tresure find : %d", data->play_coin);
			if (data->map[data->p_y][data->p_x] == EXIT && data->play_coin != data->tot_coin)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data-> t_exit,  data->p_x* TILE_SIZE, data->p_y * TILE_SIZE);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data-> t_floor,  data->p_x* TILE_SIZE, data->p_y * TILE_SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data-> t_player,  x * TILE_SIZE, y * TILE_SIZE);
			data->p_x = x;
			data->p_y = y;
		}
}

int	moving(int keycode, t_data *data)
{
	int	y;
	int	x;

	y = data->p_y;
	x = data->p_x;
	//ft_printf ("visit : %d\n", data->visit[x - 1][y]);
	ft_printf("p_y = %d ; p_x = %d\n", data->p_y, data->p_x);
	ft_printf("Touche n*%d\n", keycode);
	if (keycode == ARROW_DOWN || keycode == KEY_S)
		move_player(data, y + 1, x);
	if (keycode == ARROW_UP || keycode == KEY_W)
		move_player(data, y - 1, x);
	if (keycode == ARROW_LEFT || keycode == KEY_A)
		move_player(data, y, x - 1);
	if (keycode == ARROW_RIGHT || keycode == KEY_D)
		move_player(data, y, x + 1);
	return (0);
}

