/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:24:28 by ggispert          #+#    #+#             */
/*   Updated: 2023/08/30 16:45:08 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr(char *s, int *error)
{
	size_t	len;
	int		printed;

	if (s != NULL)
	{
		len = ft_strlen(s);
		printed = write(1, s, (len * sizeof(char)));
		if (printed == -1)
			*error = -1;
		return (printed);
	}
	else
	{
		printed = write(1, "(null)", 6);
		return (printed);
	}
}
