/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:42:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/07 23:20:13 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_overlay {
	double		d_dist_to_wall;
	double		d_wall_hit_x;
	double		d_wall_hit_y;
	long long	last_sec_change;
	long 		cur_time_ms;
	long 		last_loop_time;
	int			fps_i;
	int			frames;
	char		*fps;
	char		*player_pos_x;
	char		*player_pos_y;
	char		*dist_to_wall;
	char		*wall_hit_x;
	char		*wall_hit_y;
}	t_overlay;

typedef struct s_tex {
	char	*path_to_file;
	void	*img_ptr;
	void	*img_data_addr;
	int		width;
	int		height;
	int		bits_p_px;
	int		ln_len;
	int		endian;
}	t_tex;

typedef struct s_mlx_img {
	double		width;
	double		height;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bpp;
	int			ln_len;
	int			endian;
}	t_mlx_img;

typedef struct s_raycast {
	double			pl_pos_x;
	double			pl_pos_y;
	double			view_angle;
	double			fov_angle;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_last_pos_x;
	double			ray_last_pos_y;
	double			ray_len;
	double			angle_betw_rays;
	int				wall_side;
	unsigned int	wall_height;
	unsigned int	px_color;
}	t_raycast;

typedef struct s_map {
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	int				color_ceiling;
	int				color_floor;
	int				rows;
	int				columns;
	char 			**line_array;
	int 			line_count;
} t_map;

// base variables
typedef struct s_vars {
	// mlx instance and window
	void			*mlx_ptr;
	void			*win_ptr;
	double			win_width;
	double			win_height;

	// mlx images (main and minimap)
	t_mlx_img		main_img;
	t_mlx_img		m_map;

	// raycasting variables
	t_raycast		rc;

	// overlay
	bool			show_overlay;
	t_overlay		ol;

	// textures
	t_tex			*tx_n;
	t_tex			*tx_s;
	t_tex			*tx_e;
	t_tex			*tx_w;

	// keyboard and mouse input key state (pressed or unpressed)
	bool			*key_state;

	// comparation variable for mouse movement
	int				prev_x;

	char			**av;
	int				ac; // unused

	//! change to map struct when parsing finished
	char			*map_filename; // x unused
	int				mapfile_fd;
	char			map_str[2048];
	int				map_width;
	int				map_height;
	char			**map;
	int				floor_clr;
	int				sky_clr;

}	t_vars;


typedef struct s_dtoa {
	int			is_negative;
	long long	int_part;
	double		fractional_part;
	int			i;
	int			j;
	int			digit;
}	t_dtoa;

#endif
