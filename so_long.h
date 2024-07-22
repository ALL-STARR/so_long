/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:10:44 by marvin            #+#    #+#             */
/*   Updated: 2024/07/22 22:13:55 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>

# define WALL '1'
# define OPEN '0'
# define START 'P'
# define END 'E'
# define COLL 'C'

# define key_esc 53
# define key_w 13
# define key_a 0
# define key_s 1
# define key_d 2

# define KeyPress 2
# define KeyPressMask (1L<<0)
# define DestroyNotify 17
# define StructureNotifyMask (1L<<17)

# define Grass "grass_tile.xpm"
# define Wall "tile_wall-_1_.xpm"
# define Open "door_open.xpm"
# define Close "door_closed_1.xpm"
# define Chest "chest.xpm"
 

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *image_ptr[6];
	int  w;
	int  h;
} t_data;

typedef struct s_pos
{
	int	row;
	int	col;
}	t_pos;

typedef struct s_map
{
	t_pos	st;
	t_pos	end;
	int		size;
	int		c_count;
	t_data	data;
	char	**map;
	int		collected;

}	t_map;


int		is_valid(char **map, int **been, int row, int col);
int		floodfill(char **map, int **been, t_map *m);
char	**map_check(char *file_name);
char	**map_maker(char *f_n, int tlen);
int		counter(char *buf);
int		c_finder(char **map, t_map *m, int count);
int		is_enclosed(char **map);
int		**map_cpy(char **map);
t_map	t_mapinit(t_map m);
void	mapdisplay(char **map);
char	**reset(char ** map);
int		c_f_fill(char **map, int **been, t_map *m, t_map *pass);
int		er_finder(char **map, t_map *m);
char	**mapper(t_map *m, char *name);
void	mapsize(t_map *m, int tile_size);
int 	on_keypress(int keycode, t_map *m);
int 	on_destroy(t_data *data);
int		move(int dir, t_map *m);
t_data	image_loader(t_data data);
void	map_draw(t_map *m);

#endif