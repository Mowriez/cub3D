/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:40:06 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:14:48 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description: 
converts the initial portion of the string pointed to by str to int 
representation. Meaning if there is a non-numerical char in the str, it will
only convert up to that char. Doesn't stop at leading spaces or escape 
sequences, but can only handle one leading +/- operator.

Return value:
converted initial portion of str as int.

Particularities:
j is an indicator if nptr is negative. k is the positve return value.
"/"-chars are escape sequences. t for horizontal tab, n for newline, r for
carriage return, v for vertical tab, f for page break. ascii 9-13.

Possibly problems:
3 leading \0 access problem*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			k = (k * 10) + str[i] - '0';
		}
		else
			return (k * j);
		i++;
	}
	return (k * j);
}
