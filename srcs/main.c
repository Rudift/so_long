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
	int	i;

	i = 0;
	if (free_data)
	{
		mlx_loop_end(data->mlx_ptr);
		free (data->mlx_ptr);
		free (data->win_ptr);
		while (i < data->height)
		{
			free (data->map[i]);
			i++;
		}
		free(data->map);
		free (data);
	}
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ber_checker (char *ber_input)
{
	ber_input++;
	while (*ber_input != '.')
		ber_input++;
	if(ft_strncmp(ber_input, ".ber", 4) != 0)
	{
		error_manager(NULL, "Wrong file format !\n", 0);
	}
		return ;
}

int	main(int ac, char **av)
{
	t_data	*data = malloc(sizeof(t_data));

	if (ac != 2)
	{
		ft_printf("Error\n");
		error_manager(NULL, "Invalid number of argument\n", 0);
	}
	ber_checker(av[1]);
	ft_printf(".ber checked\n");
	data_init(data, av[1]);
	load_textures(data);
	render_map(data);
	mlx_hook(data->win_ptr, 17, 0, mlx_destroy_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &moving, data);
	mlx_loop(data->mlx_ptr);
	return(0);
}



