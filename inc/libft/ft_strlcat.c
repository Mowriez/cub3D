/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:52:02 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/19 10:15:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
takes full size of the destination buffer and guarantee NUL-termination if 
there is room. Note that room for the NUL should be included in dstsize. 
appends src to the end of dst. It will append at most dstsize - 1 
characters. It will then NUL-terminate, unless dstsize is 0 or the original dst 
string was longer than dstsize (in practice this should not happen as it means 
that either dstsize is incorrect or that dst is not a proper string).

Return value:
returns the total length of the string it tried to create. That means the 
initial length of dst plus the length of src.

Particularities:
be aware of the difference between full buffer size and length of dest. 
length is up to the first NULL-Terminator, buffer size is the allocated 
space (more char-spaces after dest string for src).

Other (maybe delete/move to general knowledge base):
restrict: restrict is a type qualifier. it symbolizes to the compiler
that during the exec of the function, the allocated object pointed at by 
dst is ONLY pointed at by dst - which means it is accessed through *p. 
Every manipulation, and be it reading, is not allowed other than through *p.
It is up to the programmer to make sure that the program follows these rules.
The benefit is that it allows gcc to optimize machine code, which could 
otherwise lead to problems with pointers.
In the case of this function it seems to be used to indicate that dst and src
should not overlap eachother, meaning not using the same memory object.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = len_dst;
	j = 0;
	if (dstsize < len_dst)
		return (len_src + dstsize);
	while (src[j] && (len_dst + j) < dstsize)
		dst[i++] = src[j++];
	if ((len_dst + j) == dstsize && j > 0)
		dst[i - 1] = '\0';
	else
		dst[i] = '\0';
	return (len_src + len_dst);
}
