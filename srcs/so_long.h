/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 12:49:18 by vdeliere          #+#    #+#             */
/*   Updated: 2025-01-08 12:49:18 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL '1'
# define FLOOR '0'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define TILE_SIZE 42

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define ESC 65307


# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*t_wall;
	void	*t_floor;
	void	*t_player;
	void	*t_coin;
	void	*t_exit;
	char	**map;
	int		height;
	int		width;
	int		p_y;
	int		p_x;
	int		**visit;
	int		tot_coin;
	int		play_coin;
	int		tot_move;
}	t_data;


/*Fonctions*/
void	error_manager(t_data *data, char *message, int free_data);
void	ber_checker(char *ber_input);
int		close_game(t_data *data, int win);
/*Init*/
void	data_init(t_data *data, char *path);


/*Map checker*/
void	map_checker(t_data *data);
void	width_checker(t_data *data);
void	char_checker(t_data *data);
void	find_pyx(t_data *data);

void	connect_checker(t_data *data);
void	dfs(t_data *data, int y, int x);
void	map_init(t_data *data, char *path);
int		map_height(int fd);

/*Utilitaire*/
void	free_array(int **tab, int size);
void	free_char_array(char **tab, int size);

/*Display*/
void	load_textures(t_data *data);
void	render_map(t_data *data);

/*Move*/
int	moving(int keycode, t_data *data);

#endif