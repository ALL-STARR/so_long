#ifndef MLX_TEST_H
# define MLX_TEST_H

# define GRASS "Grass.xpm"
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3

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