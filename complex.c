#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b);
static void	move_nodes(t_stack_node **a, t_stack_node **b);
static void	rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node);
static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node);

static void	rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, 0);
	set_current_position(*a);
	set_current_position(*b);
}
static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, 0);
	set_current_position(*a);
	set_current_position(*b);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	init_nodes(*a, *b);
	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, 0);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a > 3)
		{
			pb(b, a, 0);
			len_a--;
		}
	}
	tiny_sort(a);
	while (stack_len(*b) > 0)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}