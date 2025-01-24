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

void	clear_count(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + j, y + i, 0xD4D29B);
			j++;
		}
		i++;
	}
}

/*verifie les conditions de victoires ou de defaites*/
/*compte les collectibles ramasse*/

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
		data->end = 1;
		close_game(data);
	}
	else if (data->map[y][x] == FOES)
	{
		ft_printf ("\n\nYOU LOOSE !\n\n\n");
		data->end = 1;
		close_game(data);
	}
}

/*compte le nomvbre de mouvement*/
/*reactualise l'affichage*/

void	count_move(t_data *data)
{
	char	*str;

	str = ft_itoa(data->tot_move);
	data->tot_move++;
	clear_count(data, 10, 10);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 35, 0x4F3818, str);
	free(str);
}

/*verifie que la case ciblee n'est pas un WALL*/
/*Deplace le joueur*/
/*rafraichi l'affichage du jeu apres le mouvement*/

void	move_player(t_data *data, int y, int x)
{
	if (data->map[y][x] != WALL)
	{
		the_game(data, y, x);
		data->p_x = x;
		data->p_y = y;
		render_map(data);
		count_move(data);
	}
}

/*Gere visuelle*/

int	moving(int keycode, t_data *data)
{
	int	y;
	int	x;

	y = data->p_y;
	x = data->p_x;
	if (data->map[data->p_y][data->p_x] != EXIT)
		data->map[data->p_y][data->p_x] = FLOOR;
	if (keycode == ARROW_DOWN || keycode == KEY_S)
		move_player(data, y + 1, x);
	if (keycode == ARROW_UP || keycode == KEY_W)
		move_player(data, y - 1, x);
	if (keycode == ARROW_LEFT || keycode == KEY_A)
	{
		data->t_play_pos = data->t_play_left2;
		move_player(data, y, x - 1);
	}
	if (keycode == ARROW_RIGHT || keycode == KEY_D)
	{
		data->t_play_pos = data->t_play_right2;
		move_player(data, y, x + 1);
	}
	return (0);
}
