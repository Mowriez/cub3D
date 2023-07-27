/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_declarations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:12 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/28 00:52:14 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_DECLARATIONS_H
# define FCT_DECLARATIONS_H


// par_parser.c
int		parse_input(int argc, char**argv);

// par_utils.c

// error.c
int		err_msg(char *msg);

//not sorted yet;
int		init_struct(int argc, char**argv, t_vars **vrs);
void	ft_free(t_vars *vrs);
int		mapfile_to_arr(t_vars *vrs);

#endif
