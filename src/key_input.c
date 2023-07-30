/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/30 22:06:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs, int keycode)
{
	double	rotSpeed = 0.1;
	// if (keycode == KEY_LEFT)
	// 	vars->r_orgn = vars->r_orgn - (0.2 * vars->r_range);
	printf("key: %i", keycode);
	if (keycode == 65363)
	{
		double oldDirX = vrs->v_dir_x;
		vrs->v_dir_x = vrs->v_dir_x * cos(-rotSpeed) - vrs->v_dir_y * sin(-rotSpeed);
		vrs->v_dir_y = oldDirX * sin(-rotSpeed) + vrs->v_dir_y * cos(-rotSpeed);
		double oldPlaneX = vrs->plane_x;
		vrs->plane_x = vrs->plane_x * cos(-rotSpeed) - vrs->plane_y * sin(-rotSpeed);
		vrs->plane_y = oldPlaneX * sin(-rotSpeed) + vrs->plane_y * cos(-rotSpeed);
	}
	// if (keycode == KEY_DOWN)
	// 	vars->i_orgn = vars->i_orgn - (0.2 * vars->i_range);
	// if (keycode == KEY_UP)
	// 	vars->i_orgn = vars->i_orgn + (0.2 * vars->i_range);
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
}

int	keyboard_input(int keycode, t_vars *vrs)
{	
	printf("key: %i \n", keycode);
	if ((keycode >= KEY_LEFT && keycode <= KEY_UP) || keycode == 65363)
		pan_view(vrs, keycode);
	// if (keycode >= 18 && keycode <= 23)
		// ft_change_prime_color(vars, keycode);
	// if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	// 	ft_change_max_it(vars, keycode);
	// if (keycode == KEY_R)
	// 	ft_reset_view(vars);
	if (keycode == 65307)
		ft_free(vrs);
	return (0);
}