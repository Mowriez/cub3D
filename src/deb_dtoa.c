/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_dtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:44:30 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/03 21:01:13 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/cub3d.h"

static void	reverse_string(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	end = length - 1;
	start = 0;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static void	init_dtoa_vars(t_dtoa *dtoa_vars)
{
	dtoa_vars->is_negative = 0;
	dtoa_vars->int_part = 0;
	dtoa_vars->fractional_part = 0;
	dtoa_vars->i = 0;
	dtoa_vars->j = 0;
	dtoa_vars->digit = 0;
}

static void	add_fract_part(char *buffer, t_dtoa *dtoa_vars, int precision)
{
	buffer[dtoa_vars->i++] = '.';
	while (dtoa_vars->j < precision)
	{
		dtoa_vars->fractional_part *= 10;
		dtoa_vars->digit = (int)dtoa_vars->fractional_part;
		buffer[dtoa_vars->i++] = dtoa_vars->digit + '0';
		dtoa_vars->fractional_part -= dtoa_vars->digit;
		dtoa_vars->j++;
	}
	buffer[dtoa_vars->i] = '\0';
}

static void	set_as_negative(t_dtoa *dtoa_vars, double *num_double)
{
	dtoa_vars->is_negative = 1;
	*num_double *= -1;
}

char	*dtoa(double num_double, int precision)
{
	char		*buffer;
	t_dtoa		dtoa_vars;

	buffer = malloc(50 * sizeof(char));
	init_dtoa_vars(&dtoa_vars);
	if (num_double < 0)
		set_as_negative(&dtoa_vars, &num_double);
	dtoa_vars.int_part = (long long)num_double;
	dtoa_vars.fractional_part = num_double - dtoa_vars.int_part;
	while (dtoa_vars.int_part != 0)
	{
		buffer[dtoa_vars.i++] = (dtoa_vars.int_part % 10) + '0';
		dtoa_vars.int_part /= 10;
	}
	if (dtoa_vars.is_negative)
		buffer[dtoa_vars.i++] = '-';
	reverse_string(buffer, dtoa_vars.i);
	if (precision > 0)
		add_fract_part(buffer, &dtoa_vars, precision);
	return (buffer);
}
