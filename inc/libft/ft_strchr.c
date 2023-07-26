/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:59:42 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:15:33 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
searches for first occurence of character c in s.

Return value:
returns a pointer to the matched character or NULL if the character is not found.
The terminating null byte is considered part of the string, so that if c is 
specified as '\0', these functions return a pointer to the terminator.

Particularities:
line 35 was bullshit solution to c values bigger than ascii standard stuff, 
but I guess it's bullshit that works. Update: Now with even less bullshit.
(Typecast c as unsigned int instead of beeing braindead -255 and whatnot)

return value is tricky. if fct only returns s+i, the "const" qualifier of 
original pointer s gets discarded and compiler gets pissy(see fct arguments).
type casting fixes that error.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	c = (unsigned char) c;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *)s + i);
}
