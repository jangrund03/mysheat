#include "push_swap.h"
#include <stdbool.h>

void	set_current_position(t_stack_node *stack);
void	init_nodes(t_stack_node *a, t_stack_node *b);

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	if(!stack)
		return ;
	i = 0;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	// set_target_node(a, b);
	// set_price(a, b);
	// set_cheapest(b);
}


