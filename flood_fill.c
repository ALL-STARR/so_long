/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:37:15 by marvin            #+#    #+#             */
/*   Updated: 2024/07/15 11:37:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	is_valid(char **map, char **been, int row, int col)
{
	return ((row >= 0) && (col >= 0)
		&& (map[row][col] != WALL) && (!been[row][col]));
}

int	floodfill(char **map, char **been, t_map *m)
{
	const int	directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int			i;
	int			new_row;
	int			new_col;
	t_map		new_pos;

	i = 0;
	been[m->st.row][m->st.col] = '1';
	if (m->st.row == m->end.row && m->st.col == m->end.col)
		return (1);
	while (i++ < 4)
	{
		new_row = m->st.row + directions[i][1];
		new_col = m->st.col + directions[i][0];
		if (is_valid(map, been, new_row, new_col))
		{
			if (map[new_row][new_col] == COLL)
				m->c_count++;
			new_pos.st.row = new_row;
			new_pos.st.col = new_col;
			if (floodfill(map, been, &new_pos))
				return (1);
		}
	}
	return (0);
}

int	c_finder(char **map, t_map *m, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i++])
	{
		while (map[i][j++])
		{
			if (map[i][j] == 'C')
				count++;
			if (map[i][j] == 'P')
			{
				m->st.row = i;
				m->st.col = j;
			}
			if (map[i][j] == 'E')
			{
				m->end.row = i;
				m->end.col = j;
			}
		}
	}
	return (count);
}
