/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havu <havu@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:51:07 by havu              #+#    #+#             */
/*   Updated: 2026/11/25 15:51:38 by havu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bubble_pass(t_stack_node **a);
void		simple(t_stack_node **stack, t_stack_node **empty);

static int	bubble_pass(t_stack_node **a)
{
	int	swapped;
	int	i;
	int	size;

	swapped = 0;
	i = 0;
	size = stack_len(*a);
	while (i < size - 1)
	{
		if ((*a)->value > (*a)->next->value)
		{
			sa(a, false);
			swapped = 1;
		}
		ra(a, false);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		rra(a, false);
		i++;
	}
	return (swapped);
}

void	simple(t_stack_node **stack, t_stack_node **empty)
{
	int				swapped;
	t_stack_node	*smallest;

	(void)empty;
	swapped = 1;
	if (stack_len(*stack) < 2)
		return ;
	if (is_sorted(*stack))
		return ;
	while (swapped)
		swapped = bubble_pass(stack);
	init_nodes(*stack, NULL);
	smallest = find_smallest(*stack);
	finish_rotation(stack, smallest, 'a');
}
