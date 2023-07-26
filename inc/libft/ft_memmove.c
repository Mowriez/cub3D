/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2022/06/08 20:47:28 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
copies len bytes from string src to string dst. The two strings may overlap; 
the copy is always done in a non-destructive manner. 

Return value:
returns the original value of dst.

Particularities:
Non-destructive means, that in the case of overlapping src and dst one has to
make sure that writing to dst does not overwrite later parts of src which are
yet to be read.*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*s;

	d = dst;
	s = (char *)src;
	if (d == s)
		return (dst);
	if (s < d)
	{
		while (len > 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
