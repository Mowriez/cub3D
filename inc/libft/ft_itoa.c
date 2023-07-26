/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:07:54 by mtrautne          #+#    #+#             */
/*   Updated: 2022/07/07 10:33:25 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function description:
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

Return value:
The string representing the integer.
NULL if the allocation fails.

Parameters:
n: the integer to convert.

External functions:
malloc

Particularities:
ft_numlen: check length of number (doesnt count leading -).
ft_numgenp: Generate positive number.
ft_numgenn: Generate negatice number.
had to make all fct arguments long longs, as the edge case for INT_MIN 
would not work otherwise.*/

#include "libft.h"

static size_t	ft_numlen(long long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		n = n * -1;
	if (n >= 0)
		len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_numgenp(long long n)
{
	char	*num;
	size_t	i;
	size_t	len;

	len = ft_numlen(n);
	num = (char *) malloc((len + 1) * sizeof(*num));
	i = len - 1;
	while (i > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	num[0] = (n % 10) + '0';
	num[len] = '\0';
	return (num);
}

static char	*ft_numgenn(long long n)
{
	char	*num;
	size_t	i;
	size_t	len;

	len = ft_numlen(n) + 1;
	num = (char *) malloc((len + 1) * sizeof(*num));
	n *= -1;
	i = len - 1;
	while (i > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	num[0] = '-';
	num[len] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_numgenn(n));
	else
		return (ft_numgenp(n));
}
