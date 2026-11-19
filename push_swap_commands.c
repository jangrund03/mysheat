#include "push_swap.h"
#include <stdbool.h>

void	finish_rotation(t_stack_node **s, t_stack_node *top, char stack_name);

void	finish_rotation(t_stack_node **s, t_stack_node *top, char stack_name)
{
	while (*s != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(s, 0);
			else
				rra(s, 0);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(s, 0);
			else
				rrb(s, 0);
		}	
	}
}