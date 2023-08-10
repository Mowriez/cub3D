/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:17:09 by mtrautne          #+#    #+#             */
/*   Updated: 2023/08/10 11:21:23 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
copies up to dstsize - 1 characters from the string src to dst, NUL-terminating 
the result if dstsize is not 0.

Return value:
total length of the string ittried to create - that means the length of src.*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (len_src);
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize <= len_src)
		dst[dstsize - 1] = '\0';
	else if (dstsize != 0)
		dst[i] = '\0';
	return (len_src);
}
