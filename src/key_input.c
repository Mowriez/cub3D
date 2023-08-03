/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:46:33 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 02:35:26 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	pan_view(t_vars *vrs, int keycode)
{
	double	rotSpeed = 0.1;
	if (keycode == KEY_RIGHT)
	{
		vrs->view_angle += rotSpeed * M_PI;
	}
	else if (keycode == KEY_LEFT)
	{
		vrs->view_angle -= rotSpeed * M_PI;
	}
}

static void move(t_vars *vrs, int keycode)
{
	double	moveSpeed = .5;
	double	new_x;
	double	new_y;
	printf("player_pos_old: (%f|%f)\n", vrs->player_pos_x, vrs->player_pos_y);
	if (keycode == KEY_W)
	{
		new_x = vrs->player_pos_x + cos(vrs->view_angle) * moveSpeed;
		new_y = vrs->player_pos_y + sin(vrs->view_angle) * moveSpeed;
		printf("(int)floor(new x | y): (%i|%i)\n", (int)floor(new_x), (int)floor(new_y));
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
	else if (keycode == KEY_S)
	{
		new_x = vrs->player_pos_x - cos(vrs->view_angle) * moveSpeed;
		new_y = vrs->player_pos_y - sin(vrs->view_angle) * moveSpeed;
		printf("(int)floor(new x | y): (%i|%i)\n", (int)floor(new_x), (int)floor(new_y));
		if (vrs->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
		{
			vrs->player_pos_x = new_x;
			vrs->player_pos_y = new_y;
		}
	}
	printf("player_pos_new: (%f|%f)\n", vrs->player_pos_x, vrs->player_pos_y);
}

int	keyboard_input(int keycode, t_vars *vrs)
{	
	if ((keycode >= KEY_LEFT && keycode <= KEY_DOWN))
		pan_view(vrs, keycode);
	if (keycode >= KEY_A && keycode <= KEY_W)
		move(vrs, keycode);
	if (keycode == KEY_ESC)
		ft_free(vrs);
	visualize(vrs);
	mlx_put_image_to_window(vrs->mlx_ptr, vrs->win_ptr, vrs->img_ptr, 0, 0);
	return (0);
}