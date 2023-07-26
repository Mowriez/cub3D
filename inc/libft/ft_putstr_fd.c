/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:09:20 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 11:02:04 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Outputs the string ’s’ to the given file descriptor.

Return value:
None

Parameters:
s: The string to output.
fd: The file descriptor on which to write.

External functions:
write

Particularities:
No Null-Terminator required, as not generating a string, just writing it to 
file/standard output.*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i++], fd);
	}
}
