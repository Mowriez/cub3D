/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:42:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 15:47:58 by mtrautne         ###   ########.fr       */
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

	double	ray_angle;
	double	ray_last_pos_x;
	double	ray_last_pos_y;
	double	ray_pos_x;
	double	ray_pos_y;
	double	ray_len;
	double	ray_len_temp;
	double	angle_betw_rays;

	double	ray_precision;

	int		wall_hit;
	int		wall_side;

	unsigned int	wall_height;
	unsigned int	wall_color;
	
	bool	overlay;
	double	debug_dist_to_wall;
	double	debug_wall_hit_x;
	double	debug_wall_hit_y;
	double	last_sec_change;
	int		fps;
	int		frames;

	char	**av;
	int		ac;
}	t_vars;
