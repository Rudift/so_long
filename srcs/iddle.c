/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iddle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 09:26:14 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-23 09:26:14 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	iddle_foes(t_data *data)
{
	if (data->t_foes_pos == data->t_foes1)
	{
		data->t_foes_pos = data->t_foes2;
	}
	else
	{
		data->t_foes_pos = data->t_foes1;
	}
	return (0);
}

int	iddle_player(t_data *data)
{
	if (data->t_play_pos == data->t_play_left1)
	{
		data->t_play_pos = data->t_play_left2;
	}
	else if (data->t_play_pos == data->t_play_left2)
	{
		data->t_play_pos = data->t_play_left1;
	}
	else if (data->t_play_pos == data->t_play_right1)
	{
		data->t_play_pos = data->t_play_right2;
	}
	else
	{
		data->t_play_pos = data->t_play_right1;
	}
	return (0);
}

int	iddle(t_data *data)
{
	data->timer_iddle++;
	if (data->timer_iddle >= 10000)
	{
		data->timer_iddle = 0;
		iddle_foes(data);
		iddle_player(data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		render_map(data);
		clear_count(data, 42, 42, 10, 10);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 35, 0x4F3818,ft_itoa(data->tot_move));
	}
	return (0);
}
