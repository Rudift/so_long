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

/*Animation des squelettes*/

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

/*Animation du joueur*/

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

/*Gestionnaire d'anoimation avec timer*/

int	iddle(t_data *data)
{
	char	*str;

	str = ft_itoa(data->tot_move);
	data->timer_iddle++;
	if (data->timer_iddle >= 5000)
	{
		data->timer_iddle = 0;
		iddle_foes(data);
		iddle_player(data);
		render_map(data);
		clear_count(data, 10, 10);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 35, 0x4F3818, str);
	}
	free(str);
	return (0);
}
