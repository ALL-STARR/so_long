/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 02:02:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/19 02:02:41 by marvin           ###   ########.fr       */
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

