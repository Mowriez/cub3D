/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:42:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/28 00:48:15 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// base variables
typedef struct s_vars {
	// !game environment
	// image and window size
	double img_width;
	double img_height;
	// mlx pointers/values
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data_addr;
	// mlx random values
	int		bits_p_px;
	int		ln_len;
	int		endian;
	// source file adresses
	char	*map_path;
	int		mapfile_fd; //close on return
	char	map_str[2048];
	int		map_width;
	int		map_height;
	int		**map; //free on return
	char	*tx_n;
	char	*tx_s;
	char	*tx_e;
	char	*tx_w;
	// floor and sky color;
	int		floor_clr;
	int		sky_clr;

	// !player
	// player position
	double	pos_x;
	double	pos_y;
	// view direction
	double	dir_x;
	double	dir_y;
	// field of view vector
	double	fov_x;
	double	fov_y;

	// !delete later
	char	**av;
	int		ac;
}	t_vars;
