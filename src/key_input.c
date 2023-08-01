/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/01 19:14:05 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs, int keycode)
{
	double	rotSpeed = 0.1;
	// if (keycode == KEY_LEFT)
	// 	vars->r_orgn = vars->r_orgn - (0.2 * vars->r_range);
	printf("key: %i", keycode);
	if (keycode == KEY_RIGHT)
	{
		vrs->view_angle += rotSpeed * M_PI;
	}
	if (keycode == KEY_LEFT)
	{
		vrs->view_angle -= rotSpeed * M_PI;
	}
	// if (keycode == KEY_W)
	// 	vars->i_orgn = vars->i_orgn + (0.2 * vars->i_range);
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
}

static void move(t_vars *vrs, int keycode)
{
	double	moveSpeed = .5;
	if (keycode == KEY_W)
	{
		if (vrs->map[(int)(vrs->pos_y + sin(vrs->view_angle) * moveSpeed)][(int)(vrs->pos_x + cos(vrs->view_angle) * moveSpeed)] == '0')
		{
			vrs->pos_x += cos(vrs->view_angle) * moveSpeed;
			vrs->pos_y += sin(vrs->view_angle) * moveSpeed;
		}
	}
	else if (keycode == KEY_S)
	{
		if (vrs->map[(int)(vrs->pos_y - sin(vrs->view_angle) * moveSpeed)][(int)(vrs->pos_x - cos(vrs->view_angle) * moveSpeed)] == '0')
		{
			vrs->pos_x -= cos(vrs->view_angle) * moveSpeed;
			vrs->pos_y -= sin(vrs->view_angle) * moveSpeed;
		}
	}
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
}

int	keyboard_input(int keycode, t_vars *vrs)
{	
	printf("key: %i", keycode);
	if ((keycode >= KEY_LEFT && keycode <= KEY_UP))
		pan_view(vrs, keycode);
	if (keycode > KEY_A && keycode <= KEY_W)
		move(vrs, keycode);
	// // if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	// // 	ft_change_max_it(vars, keycode);
	// // if (keycode == KEY_R)
	// // 	ft_reset_view(vars);
	if (keycode == KEY_ESC)
		ft_free(vrs);
	return (0);
}