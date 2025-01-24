/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 12:22:42 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-08 12:22:42 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_manager(t_data *data, char *message, int free_data)
{
	ft_printf("I'm in the error manager\n");
	if (free_data == 1 || free_data == 2)
	{
		free_char_array(data->map, data->height);
	}
	if (free_data == 2)
	{
		destroy_images(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
	ft_printf("Error\n");
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ber_checker(t_data *data, char *ber_input)
{
	ber_input++;
	while (*ber_input != '.')
		ber_input++;
	if (ft_strncmp(ber_input, ".ber", 4) != 0)
		error_manager(data, "Wrong file format !\n", 0);
	return ;
}

int	close_game(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	if (data->end == 0)
	{
		ft_printf("\n\no====||==================>\n");
		ft_printf("ARE YOU FLEEING ? COWARD !\n");
		ft_printf("<==================||====o\n\n\n");
	}
	destroy_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_char_array(data->map, data->height);
	free(data->mlx_ptr);
	free(data);
	exit(EXIT_SUCCESS);
}

int	esc_game(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		close_game(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		error_manager(NULL, "Malloc error\n", 0);
	if (ac != 2)
		error_manager(data, "Invalid number of argument\n", 0);
	ber_checker(data, av[1]);
	data_init(data, av[1]);
	load_textures(data);
	render_map(data);
	mlx_key_hook(data->win_ptr, &esc_game, data);
	mlx_hook(data->win_ptr, 17, 0, close_game, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &moving, data);
	clear_count(data, 10, 10);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 35, 0x4F3818, "0");
	mlx_loop_hook(data->mlx_ptr, &iddle, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
