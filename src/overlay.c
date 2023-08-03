/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:49:08 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 15:49:02 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	count_fps(t_vars *vrs)
{
	struct timeval	s_cur_time;
	double			time_sec;

	gettimeofday(&s_cur_time, NULL);
	time_sec = s_cur_time.tv_sec;
	if (time_sec - vrs->last_sec_change == 0)
		vrs->frames++;
	else
	{
		vrs->fps = vrs->frames;
		vrs->frames = 0;
		vrs->last_sec_change = time_sec;
	}
}

void	draw_debugging_overlay(t_vars *vrs)
{
	char	player_pos_x[50];
	char	player_pos_y[50];
	char	dist_to_wall[50];
	char	debug_wall_hit_x[50];
	char	debug_wall_hit_y[50];

	count_fps(vrs);
	char *fps = ft_itoa(vrs->fps);
	dtostr(vrs->player_pos_x, player_pos_x, 3);
	dtostr(vrs->player_pos_y, player_pos_y, 3);
	dtostr(vrs->debug_dist_to_wall, dist_to_wall, 3);
	dtostr(vrs->debug_wall_hit_x, debug_wall_hit_x, 3);
	dtostr(vrs->debug_wall_hit_y, debug_wall_hit_y, 3);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 15, 0x0039FF14, "Player position x, y:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 15, 0x0039FF14, player_pos_x);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 230, 15, 0x0039FF14, player_pos_y);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 30, 0x0039FF14, "Wall intersection:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 180, 30, 0x0039FF14, debug_wall_hit_x);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 230, 30, 0x0039FF14, debug_wall_hit_y);
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 15, 45, 0x0039FF14, "fps:");
	mlx_string_put(vrs->mlx_ptr, vrs->win_ptr, 80, 45, 0x0039FF14, fps);
	free(fps);
}

static void reverseString(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void	dtostr(double num_double, char *buffer, int precision)
{
	int			is_negative;
	long long	int_part;
	double		fractional_part;
	int			i;
	int			j;
	int			digit;

	i = 0;
	j = 0;
	digit = 0;
	is_negative = 0;
	if (num_double < 0)
	{
		is_negative = 1;
		num_double = -num_double;
	}
	int_part = (long long)num_double;
	fractional_part = num_double - int_part;

	// Convert the integer part to string
	while(int_part != 0)
	{
		buffer[i++] = (int_part % 10) + '0';
		int_part /= 10;
	}
	if (is_negative)
		buffer[i++] = '-';
	reverseString(buffer, i);
	// Handle fractional part
	if (precision > 0)
	{
		buffer[i++] = '.';
		// Convert the fractional part to string
		while (j < precision)
		{
			fractional_part *= 10;
			digit = (int)fractional_part;
			buffer[i++] = digit + '0';
			fractional_part -= digit;
			j++;
		}
	}
	buffer[i] = '\0';
}
