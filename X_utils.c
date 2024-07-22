/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:42:06 by thomvan-          #+#    #+#             */
/*   Updated: 2024/07/22 22:21:24 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	//mlx_destroy_image(data->mlx_ptr, data->image_ptr[0]);
	//mlx_destroy_image(data->mlx_ptr, data->image_ptr[1]);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keycode, t_map *m)
{
	if (keycode == key_esc)
		on_destroy(&m->data);
	if (keycode == key_w || keycode == key_a || keycode == key_s
		|| keycode == key_d)
		move(keycode, m);
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
	m->data.w = (i) * tile_size;
	m->data.h = (j) * tile_size;
	return ;
}