/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:49:30 by marvin            #+#    #+#             */
/*   Updated: 2024/07/21 16:31:34 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int arc, char **arv)
{
	t_map	m;
	
	if(arc != 2)
	{
		ft_printf("Error : please only provide the map's name\n");
		return (1);
	}
	m = t_mapinit(m);
	if (!mapper(&m, arv[1]))
		return (1);
	mapdisplay(m.map);
	mapsize(&m, 64);
	m.data.mlx_ptr = mlx_init();
	if (!m.data.mlx_ptr)
		return (1);
	m.data.win_ptr = mlx_new_window(m.data.mlx_ptr, m.data.h, m.data.w, "hi :)");
	if (!m.data.win_ptr)
		return (free(m.data.mlx_ptr), 1);
	mlx_hook(m.data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &m);
	mlx_hook(m.data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &m);
	mlx_loop(m.data.mlx_ptr);
	return (0);
}

t_map	t_mapinit(t_map m)
{
	m.c_count = 0;
	m.collected = 0;
	m.map = NULL;
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
	int	**cpy;

	m->map = map_check(name);
	if (!m->map)
		return (NULL);
	m->c_count = c_finder(m->map, m, 0);
	cpy = map_cpy(m->map);
	if (!floodfill(m->map, map_cpy(m->map), m) || !c_f_fill(m->map, cpy, m, m))
		ft_printf("Error : path missing\n");
	return (m->map);
}

