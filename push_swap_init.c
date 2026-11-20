#include "push_swap.h"
#include <stdbool.h>
# include <limits.h>

void	set_current_position(t_stack_node *stack);
void	init_nodes(t_stack_node *a, t_stack_node *b);
static void	set_target_node(t_stack_node *a, t_stack_node *b);
void	set_price(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *b);

void	set_cheapest(t_stack_node *b)
{
	long			cheapest_push_price;
	t_stack_node	*best_match_node;

	if (!b)
		return ;
	cheapest_push_price = LONG_MAX;
	while (b)
	{
		if (b->push_price < cheapest_push_price)
		{
			cheapest_push_price = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match;
	
	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				target = current_a;
				best_match = current_a->value;
			}
			current_a = current_a->next;
		}
		if (best_match = LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

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
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}


