/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:42:06 by thomvan-          #+#    #+#             */
/*   Updated: 2024/07/23 20:50:54 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->image_ptr[0]);
	mlx_destroy_image(d->mlx_ptr, d->image_ptr[1]);
	mlx_destroy_image(d->mlx_ptr, d->image_ptr[2]);
	mlx_destroy_image(d->mlx_ptr, d->image_ptr[3]);
	mlx_destroy_image(d->mlx_ptr, d->image_ptr[4]);
	mlx_destroy_image(d->mlx_ptr, d->image_ptr[5]);
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	free(d->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_map *m)
{
	if (keycode == KEY_ESC)
		on_destroy(&m->d);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		if (keycode == KEY_W)
			move(3, m);
		else
			move(keycode, m);
	}
	return (0);
}

void	mapsize(t_map *m, int tile_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i] != NULL)
		i++;
	while (m->map[0][j] != '\0')
		j++;
	m->d.w = (i) * tile_size;
	m->d.h = (j) * tile_size;
	return ;
}
