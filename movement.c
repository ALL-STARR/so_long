/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 02:02:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/22 22:17:33 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int dir, t_map *m)
{
	const int	directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	t_pos	new;

	new.col = m->st.col + directions[dir][0];
	new.row = m->st.row + directions[dir][1];
	if (m->map[new.col][new.row] != WALL)
	{
		m->st = new;
		if (m->map[new.col][new.row] == COLL)
		{
			m->map[new.col][new.row] = OPEN;
			m->collected++;
		}
		if (m->map[new.col][new.row] == 'E' && m->collected == m->c_count)
			return (2);
		return (1);
	}
	else
		return (0);
}

void	map_draw(t_map *m)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
				mlx_put_image_to_window(m->data.mlx_ptr, m->data.win_ptr, m->data.image_ptr[0], x * 32, y * 32);
			if (m->map[y][x] == WALL)
				mlx_put_image_to_window(m->data.mlx_ptr, m->data.win_ptr, m->data.image_ptr[1], x * 32, y * 32);
			if (m->map[y][x] == COLL)
				mlx_put_image_to_window(m->data.mlx_ptr, m->data.win_ptr, m->data.image_ptr[2], x * 32, y * 32);
			if (m->map[y][x] == END)
				mlx_put_image_to_window(m->data.mlx_ptr, m->data.win_ptr, m->data.image_ptr[3], x * 32, y * 32);
			//if (m->map[y][x] == START)
			//	mlx_put_image_to_window(m->data.mlx_ptr, m->data.win_ptr, m->data.image_ptr[4], x * 32, y * 32);
			x++;
		}
		y++;
	}
}

