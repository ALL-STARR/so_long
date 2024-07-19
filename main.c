/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:49:30 by marvin            #+#    #+#             */
/*   Updated: 2024/07/19 17:12:34 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		c_count;
	char	**cpy;
	t_map	m;

	m = t_mapinit(m);
	m.map = map_check("map.ber");
	mapdisplay(m.map);
	c_count = c_finder(m.map, &m, 0);
	cpy = map_cpy(m.map);
	if (!floodfill(m.map, cpy, &m))
		ft_printf("wowowow the map is not valid");
	if (m.c_count != c_count)
		return (1);
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
