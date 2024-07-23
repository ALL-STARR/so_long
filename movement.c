/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 02:02:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/23 20:11:03 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int dir, t_map *m)
{
	const int	directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	t_pos	new;

	new.col = m->st.col + directions[dir][0];
	new.row = m->st.row + directions[dir][1];
	if (m->map[new.row][new.col] != WALL)
	{
		drawer(m, m->st.col * 32, m->st.row * 32, 0);
		if (m->map[m->st.row][m->st.col] == END)
			drawer(m, m->st.col * 32, m->st.row * 32, 3);
		m->st = new;
		if (m->map[new.row][new.col] == COLL)
		{
			m->collected++;
			m->map[new.row][new.col] = OPEN;
			drawer(m, new.col * 32, new.row * 32, 0);
		}
		if (m->map[new.row][new.col] == 'E' && m->collected == m->c_count)
			drawer(m, m->st.col * 32, m->st.row * 32, 5);
		drawer(m, m->st.col * 32, m->st.row * 32, 4);
		return (1);
	}
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
				mlx_put_image_to_window(m->d.mlx_ptr, m->d.win_ptr, m->d.image_ptr[0], x * 32, y * 32);
			if (m->map[y][x] == WALL)
				mlx_put_image_to_window(m->d.mlx_ptr, m->d.win_ptr, m->d.image_ptr[1], x * 32, y * 32);
			if (m->map[y][x] == COLL)
				mlx_put_image_to_window(m->d.mlx_ptr, m->d.win_ptr, m->d.image_ptr[2], x * 32, y * 32);
			if (m->map[y][x] == END)
				mlx_put_image_to_window(m->d.mlx_ptr, m->d.win_ptr, m->d.image_ptr[3], x * 32, y * 32);
			if (m->map[y][x] == START)
				mlx_put_image_to_window(m->d.mlx_ptr, m->d.win_ptr, m->d.image_ptr[4], x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	drawer(t_map *m, int x, int y, int i)
{
	mlx_put_image_to_window(m->d.mlx_ptr, m->d.win_ptr, m->d.image_ptr[i], x, y);
}
