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
#include <stdbool.h>

void	finish_rotation(t_stack_node **s, t_stack_node *top, char here);

void	finish_rotation(t_stack_node **s, t_stack_node *top, char here)
{
	while (*s != top)
	{
		if (here == 'a')
		{
			if (top->above_median)
				ra(s, 0);
			else
				rra(s, 0);
		}
		else if (here == 'b')
		{
			if (top->above_median)
				rb(s, 0);
			else
				rrb(s, 0);
		}
	}
}
