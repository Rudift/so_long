/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 08:38:41 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-10 08:38:41 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(int fd)
{
	char	*next_line;
	int		height;

	height = 0;
	next_line = get_next_line(fd);
	while ((next_line))
	{
		free (next_line);
		height ++;
		next_line = get_next_line(fd);
	}
	return (height);
}

void	map_init(t_data *data, char *path)
{
	int		fd;
	int		i;
	char	*next_line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		error_manager(data, "Map can't be open\n", 0);
	}
	data->height = map_height(fd);
	close(fd);
	data->map = malloc(data->height * sizeof(char *));
	if (data->map == NULL)
		error_manager(data, "Map malloc error\n", 0);
	fd = open(path, O_RDONLY);
	while (i < data->height)
	{
		next_line = get_next_line(fd);
		data->map[i++] = ft_strdup(next_line);
		free (next_line);
	}
	close (fd);
	data->width = ft_strlen(data->map[0]) - 1;
}
