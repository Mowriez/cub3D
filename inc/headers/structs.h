/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:42:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/04 09:00:05 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// base variables
typedef struct s_vars {
	double			img_width;
	double			img_height;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data_addr;
	int				bits_p_px;
	int				ln_len;
	int				endian;

	char			*map_filename;
	int				mapfile_fd;
	char			map_str[2048];
	int				map_width;
	int				map_height;
	char			**map;
	struct s_text	*tx_n;
	struct s_text	*tx_s;
	struct s_text	*tx_e;
	struct s_text	*tx_w;
	int				floor_clr;
	int				sky_clr;

	double			player_pos_x;
	double			player_pos_y;
	double			view_angle;
	double			fov_angle;
	double			ray_angle;
	double			ray_last_pos_x;
	double			ray_last_pos_y;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_len;
	double			angle_betw_rays;
	double			ray_precision;

	int				wall_hit;
	int				wall_side;
	unsigned int	wall_height;
	unsigned int	wall_color;

	bool			overlay;
	double			debug_dist_to_wall;
	double			debug_wall_hit_x;
	double			debug_wall_hit_y;
	double			last_sec_change;
	int				fps;
	int				frames;

	void			*m_img_ptr;
	void			*m_img_data_addr;
	int				m_width;
	int				m_height;
	int				m_bits_p_px;
	int				m_ln_len;
	int				m_endian;
	unsigned int	m_color_wall;
	unsigned int	m_color_floor;
	unsigned int	m_color_player;
	unsigned int	m_color_view_cone;

	bool			*key_state;

	char			**av;
	int				ac;
}	t_vars;

typedef struct s_dtoa {
	int			is_negative;
	long long	int_part;
	double		fractional_part;
	int			i;
	int			j;
	int			digit;
}	t_dtoa;

typedef struct s_overlay {
	char	*fps;
	char	*player_pos_x;
	char	*player_pos_y;
	char	*dist_to_wall;
	char	*debug_wall_hit_x;
	char	*debug_wall_hit_y;
}	t_overlay;

typedef struct s_text {
	char	*path_to_file;
	void	*addr;
	int		width;
	int		height;
}	t_text;

#endif
