/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:10:44 by marvin            #+#    #+#             */
/*   Updated: 2024/07/19 16:11:29 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <unistd.h>

# define WALL '1'
# define OPEN '0'
# define START 'P'
# define END 'E'
# define COLL 'C'

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

int		is_valid(char **map, char **been, int row, int col);
int		floodfill(char **map, char **been, t_map *m);
char	**map_check(char *file_name);
char	**map_maker(char *f_n, int tlen);
int		counter(char *buf);
int		c_finder(char **map, t_map *m, int count);
int		is_enclosed(char **map);
char	**map_cpy(char **map);
t_map	t_mapinit(t_map m);
void	mapdisplay(char **map);

#endif