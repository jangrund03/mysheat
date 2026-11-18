#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack);
void	rra(t_stack_node **a, bool checker);
void	rrb(t_stack_node **b, bool checker);
void	rrr(t_stack_node **a, t_stack_node **b, bool checker);

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last_node(first);
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
