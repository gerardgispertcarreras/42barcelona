/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:17:11 by ggispert          #+#    #+#             */
/*   Updated: 2023/09/07 11:31:21 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

typedef struct s_stack
{
	int	*values;
	int	size;
}				t_stack;

void	push_swap(t_stack *A, t_stack *B, int max_size);
void	convert_arg_to_stack(int argc, char **argv, t_stack *A);
