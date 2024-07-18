#ifndef MLX_TEST_H
# define MLX_TEST_H

# define GRASS "Grass.xpm"

typedef struct s_map
{
	int	size;
	int c_count;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

#endif