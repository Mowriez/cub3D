/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:20:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/09 08:07:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vrs;

	if (check_input(argc, argv))
		return (1);
	if (parse_init_struct(argv, &vrs))
		return (1);
	mlx_hook(vrs.win_ptr, 2, 1L << 0, set_key_status_pressed, &vrs);
	mlx_hook(vrs.win_ptr, 3, 1L << 1, set_key_status_free, &vrs);
	mlx_hook(vrs.win_ptr, 4, 1L << 2, set_mouse_key_status, &vrs);
	mlx_hook(vrs.win_ptr, 6, 1L << 6, pan_view_mouse, &vrs);
	mlx_hook(vrs.win_ptr, 17, 0L, ft_free, &vrs);
	mlx_loop_hook(vrs.mlx_ptr, visualizer, &vrs);
	mlx_loop(vrs.mlx_ptr);
	ft_free(&vrs);
	return (0);
}

int	ft_free(t_vars *vrs)
{
	ft_free_map(&vrs->map);
	ft_free_char_array(vrs->map.map);
	mlx_destroy_image(vrs->mlx_ptr, vrs->main_img.img_ptr);
	mlx_destroy_image(vrs->mlx_ptr, vrs->m_map.img_ptr);
	mlx_destroy_image(vrs->mlx_ptr, vrs->tx_n.img_ptr);
	mlx_destroy_image(vrs->mlx_ptr, vrs->tx_e.img_ptr);
	mlx_destroy_image(vrs->mlx_ptr, vrs->tx_s.img_ptr);
	mlx_destroy_image(vrs->mlx_ptr, vrs->tx_w.img_ptr);
	mlx_destroy_window(vrs->mlx_ptr, vrs->win_ptr);
	exit(1);
}
