#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
 

# define GRASS "full_tile.xpm"

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *image_ptr[2];
	int  width;
	int  height;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image_ptr[0]);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr[1]);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		on_destroy(data);
	if (keysym == XK_space)
		on_destroy(data);
	return (0);
}
 
int main(void)
{

	t_data data;
	data.width = 100;
	data.height = 100;
 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 560, 420, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	
	data.image_ptr[1] = mlx_xpm_file_to_image(data.mlx_ptr, GRASS, &data.width, &data.height);
	data.image_ptr[0] = mlx_xpm_file_to_image(data.mlx_ptr, "bars.xpm", &data.width, &data.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image_ptr[1], 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image_ptr[0], 0, 0);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask,	&on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}