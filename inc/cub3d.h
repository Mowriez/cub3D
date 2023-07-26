/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:48:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/26 23:54:51 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// System Headers
#include <math.h>
#include <stdio.h>

// Project specific headers
#include "colors.h"
#include "./libft/libft.h"
#include "./mlx/minilibx-linux/mlx.h"
#include "./mlx/minilibx-linux/mlx_int.h"

// OS specific Headers
#ifdef __linux__
# include "./mlx/minilibx-linux/mlx.h"

#elif defined(__APPLE__)
# include "./mlx/minilibx_opengl_20191021/mlx.h"

#else
# error "Unsupported operating system"
# endif

