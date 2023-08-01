/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:48:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/30 21:12:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// System Headers
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <float.h>

// Project specific headers
#include "../libft/libft.h"
#include "key_macros.h"
#include "colors.h"
#include "struct.h"
#include "fct_declarations.h"

// OS specific mlx headers
#ifdef __linux__
# include "../mlx/minilibx-linux/mlx.h"

#elif defined(__APPLE__)
# include "../mlx/minilibx_opengl_20191021/mlx.h"

#else
# error "Unsupported operating system"
# endif

#endif