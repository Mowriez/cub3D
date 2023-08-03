/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:42:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 02:25:50 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// base variables
typedef struct s_vars {
	double img_width;
	double img_height;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data_addr;

	int		bits_p_px;
	int		ln_len;
	int		endian;

	char	*map_filename;
	int		mapfile_fd; //close on return
	char	map_str[2048];
	int		map_width;
	int		map_height;
	char	**map;
//	char	*tx_n;
//	char	*tx_s;
//	char	*tx_e;
//	char	*tx_w;

	int		floor_clr;
	int		sky_clr;

	double	player_pos_x;
	double	player_pos_y;
	double	view_angle;
	double	fov_angle;

	double	cam_plane_ray_int_x;
	double	cam_plane_ray_int_y;

	double	ray_angle;
	double	ray_last_pos_x;
	double	ray_last_pos_y;
	double	ray_pos_x;
	double	ray_pos_y;
	double	ray_len;
	
	double	angle_betw_rays;

	double	ray_precision;
	double	ray_dist;
	int		ray_dir_ns;
	int		ray_dir_ew;

	int		wall_hit;
	int		wall_side;

	unsigned int	wall_height;
	unsigned int	wall_color;

	char	**av;
	int		ac;
}	t_vars;
