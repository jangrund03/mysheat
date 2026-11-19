#include "push_swap.h"
#include <limits.h>

static t_stack_node	*find_highest(t_stack_node *stack);
static t_stack_node	*find_smallest(t_stack_node *stack);
void	tiny_sort(t_stack_node **a);
void	handle_five(t_stack_node **a, t_stack_node **b);

static t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest;
	int				highest_val;

	if (!stack)
		return(NULL);
	highest_val = INT_MIN;
	while(stack)
	{
		if (stack->value > highest_val)
		{
			highest_val = stack->value;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

static t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;
	int				smallest_val;

	if (!stack)
		return(NULL);
	smallest = stack;
	smallest_val = INT_MAX;
	while(stack)
	{
		if (stack->value < smallest_val)
		{
			smallest_val = stack->value;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}


// handle 3
void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, 0);
	else if ((*a)->next == highest)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
	tiny_sort(a);
	while (stack_len(*b) > 0)
		pa(a, b, false);
}
