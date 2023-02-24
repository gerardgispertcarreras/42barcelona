/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:50:00 by ggispert          #+#    #+#             */
/*   Updated: 2023/02/21 19:40:19 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	i = -1;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)(haystack));
	while (haystack[++i] && i + nlen <= len)
	{
		j = -1;
		while (++j < nlen && needle[j] == haystack[i + j])
			;
		if (j == nlen)
			return ((char *)(haystack + i));
	}
	return (NULL);
}
