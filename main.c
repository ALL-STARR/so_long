/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:49:30 by marvin            #+#    #+#             */
/*   Updated: 2024/07/23 20:53:35 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int arc, char **arv)
{
	t_map	m;

	if (arc != 2)
	{
		ft_printf("Error : please only provide the map's name\n");
		return (1);
	}
	m = t_mapinit(m);
	if (!mapper(&m, arv[1]))
		return (1);
	mapsize(&m, 32);
	m.d.mlx_ptr = mlx_init();
	m.d = image_loader(m.d);
	if (!m.d.mlx_ptr)
		return (1);
	m.d.win_ptr = mlx_new_window(m.d.mlx_ptr, m.d.h, m.d.w, "hi :)");
	if (!m.d.win_ptr)
		return (free(m.d.mlx_ptr), free(m.d.image_ptr), 1);
	map_draw(&m);
	mlx_hook(m.d.win_ptr, KEYPRESS, (1L << 0), &on_keypress, &m);
	mlx_hook(m.d.win_ptr, DESNOTIFY, (1L << 17), &on_destroy, &m.d);
	mlx_loop(m.d.mlx_ptr);
	return (0);
}

t_map	t_mapinit(t_map m)
{
	m.c_count = 0;
	m.collected = 0;
	m.map = NULL;
	m.moves = 0;
	return (m);
}

void	mapdisplay(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	return ;
}

char	**mapper(t_map *m, char *name)
{
	int	c_count;

	m->map = map_check(name);
	if (!m->map)
		return (NULL);
	m->c_count = c_finder(m->map, m, 0, 0);
	if (!floodfill(m->map, map_cpy(m->map), m)
		|| !c_f_fill(m->map, map_cpy(m->map), m, m))
	{
		ft_printf("Error : path missing\n");
		return (NULL);
	}
	m->collected = 0;
	if (er_finder(m->map))
	{
		ft_printf("Error : map invalid\ncharacters allowed : C 0 1 E P\n");
		return (NULL);
	}
	return (m->map);
}

t_data	image_loader(t_data d)
{
	int		w;
	int		h;

	w = 32;
	h = 32;
	d.image_ptr[0] = mlx_xpm_file_to_image(d.mlx_ptr, GRASS, &w, &h);
	d.image_ptr[1] = mlx_xpm_file_to_image(d.mlx_ptr, WALL_TILE, &w, &h);
	d.image_ptr[2] = mlx_xpm_file_to_image(d.mlx_ptr, CHEST, &w, &h);
	d.image_ptr[3] = mlx_xpm_file_to_image(d.mlx_ptr, CLOSE, &w, &h);
	d.image_ptr[4] = mlx_xpm_file_to_image(d.mlx_ptr, PLAYER, &w, &h);
	d.image_ptr[5] = mlx_xpm_file_to_image(d.mlx_ptr, OPEN_TILE, &w, &h);
	return (d);
}
