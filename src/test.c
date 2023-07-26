#include	"/home/mtrautne/projects/12_cub3D/cub3d_gh/inc/mlx/minilibx-linux/mlx.h"
#include	"/home/mtrautne/projects/12_cub3D/cub3d_gh/inc/mlx/minilibx-linux/mlx_int.h"
#include <math.h>

int main(void)
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			width;
	double			height;
	char			*title = "cubed";

	mlx_ptr = mlx_init();
	width = 1200;
	height = (double)round(width / 1.77);
	win_ptr = mlx_new_window(mlx_ptr, width, height, title);
	mlx_loop(mlx_ptr);
	return (0);
}
