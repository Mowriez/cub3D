/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_drawer_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:19:31 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/08 12:29:22 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	draw_vertical(int x, int y, t_vars *vrs)
{
	x = (int)(vrs->win_width / 2) - 1;
	while (x <= (vrs->win_width / 2) + 1)
	{
		y = (int)((vrs->win_height / 2) - 9);
		while (y < ((vrs->win_height / 2) + 9))
		{
			if (y < ((vrs->win_height / 2)) - 3
				|| y > ((vrs->win_height / 2)) + 3)
				print_pixel(x, y, vrs, 0x0039FF14);
			y++;
		}
		x++;
	}
}

static void	draw_horizontal(int x, int y, t_vars *vrs)
{
	y = (int)(vrs->win_height / 2) - 1;
	while (y <= (vrs->win_height / 2) + 1)
	{
		x = (int)((vrs->win_width / 2) - 10);
		while (x < ((vrs->win_width / 2) + 10))
		{
			if (x < ((vrs->win_width / 2) - 2)
				|| x > ((vrs->win_width / 2) + 2))
				print_pixel(x, y, vrs, 0x0039FF14);
			x++;
		}
		y++;
	}
}

void	draw_scope(t_vars *vrs)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_vertical(x, y, vrs);
	draw_horizontal(x, y, vrs);
}
