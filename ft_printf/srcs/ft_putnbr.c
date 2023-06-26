/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:24:28 by ggispert          #+#    #+#             */
/*   Updated: 2023/06/25 21:22:13 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int	ft_putint(int n, int *error)
{
	int	dig;
	int	wr;
		
	dig = 1;
	if (n == -2147483648)
		dig = ft_putstr("-2147483648", error);
	else if (n < 0)
	{
	wr = write(1, "-", 1);
	n = -n;
	if (wr != -1)
		dig += ft_putint(n, error); //pr
	else
		*error = -1;
	}
	else
	{
		if (n/10 != 0)
			dig += ft_putint(n/10, error);
		if (*error != -1)
			wr = write(1, &(char){'0' + n%10}, 1);
		if (wr == -1)
			*error = -1;
	}
	return (dig);
}

int	ft_putuint(unsigned int n, int *error)
{
	int	dig;
	int wr;
	
	dig = 1;
	if (n/10 != 0)
		dig += ft_putuint(n/10, error);
	wr = write(1, &(char){'0' + n%10}, 1);
	if (wr == -1)
		*error = -1;
	return (dig);
}

int	ft_putuintHex(unsigned int x, char mayus, int *error)
{
	int	dig;
	int wr;
		
	dig = 1;
	if (x/16 != 0)
		dig += ft_putuintHex(x/16, mayus, error);
	if (x%16 < 10)
		wr = write(1, &(char){'0' + x%16}, 1);
	else
	{
		if (mayus)
			wr = write(1, &(char){'A' + x%16 - 10}, 1);
		else
			wr = write(1, &(char){'a' + x%16 - 10}, 1);
	}
	if (wr == -1)
		*error = -1;
	return (dig);
}
