/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:49:30 by marvin            #+#    #+#             */
/*   Updated: 2024/02/10 16:49:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		c_count;
	char	**cpy;
	t_map	*m;

	m = (t_map *)malloc(sizeof(t_map));
    if (!m)
        return (1);
	m->map = map_check("map.ber");
	if (!m->map)
	{
		free(m);
		return (1);
	}
	c_count = c_finder(m->map, m, 0);
	cpy = map_cpy(m->map);
	if (!floodfill(m->map, cpy, m))
		ft_printf("wowowow the map is not valid");
	if (m->c_count != c_count)
	{
		free(m);
		return (1);
	}
	free(m);
	return (0);
}
