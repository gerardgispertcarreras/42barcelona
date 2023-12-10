/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggispert <ggispert@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:23:55 by ggispert          #+#    #+#             */
/*   Updated: 2023/12/10 16:51:33 by ggispert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	This function executes the moves in the simple algorithm. It
	just executes the moves.
	Params:
		a: stack a.
		b: stack b.
		moves: number of moves.
		selected: selected stack.
*/
void	execute_moves_simple(t_stack *a, t_stack *b, int moves, char selected)
{
	int		direction;
	char	*operation;

	decide_move_flow(moves, &direction, &operation, selected);
	while (moves != 0)
	{
		operate(a, b, operation);
		moves += direction;
	}
	free(operation);
}

/*
	This function executes the moves in the complex algorithm. It
	adds extra logic to be more efficient.
	Params:
		a: stack a.
		b: stack b.
		moves: number of moves.
		n: number it is searching.
*/
char	execute_moves_complex(t_stack *a, t_stack *b, int moves, int n)
{
	char	swap_needed;
	char	*operation;
	int		direction;

	swap_needed = 0;
	decide_move_flow(moves, &direction, &operation, 'b');
	while (moves != 0)
	{
		if (b->top->value == (n - 1))
		{
			operate(a, b, "pa");
			swap_needed = 1;
			if (direction == -1)
				moves += direction;
		}
		else
		{
			operate(a, b, operation);
			moves += direction;
		}
	}
	free(operation);
	return (swap_needed);
}
