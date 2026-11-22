#include "push_swap.h"

static void	pre_index(t_stack_node **stack);
static int	chunk_siz(int size);
static void	push_chunks(t_stack_node **a, t_stack_node **b);
static void	push_back(t_stack_node **a, t_stack_node **b);
void		medium(t_stack_node **a, t_stack_node **b);

static void	push_chunks(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	chunk_size;
	int	pushed;
	int	limit;

	size = stack_len(*a);
	chunk_size = size / chunk_siz(size) + 1;
	pushed = 0;
	limit = chunk_size;
	while (pushed < size)
	{
		if ((*a)->pre_index < limit)
		{
			pb(b, a, 0);
			pushed++;
			if((*b)->pre_index > limit - chunk_size / 2)
				rb(b, 0);
		}
		else
			ra(a, 0);
		if (pushed >= limit)
			limit += chunk_size;
	}
}

static void	push_back(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max;
	while(stack_len(*b) > 0)
	{
		max = find_highest(*b);
		finish_rotation(b, max, 'b');
		pa(a, b, 0);
	}
}

static int	chunk_siz(int size)
{
	if (size <= 100)
		return (5);
	return (11);
}

static void	pre_index(t_stack_node **stack)
{
	t_stack_node	*inner;
	t_stack_node	*outer;
	int				index;


	if (!stack || !(*stack))
		return ;
	outer = *stack;
	while (outer)
	{
		index = 0;
		inner = *stack;
		while (inner)
		{
			if (inner->value < outer->value)
				index++;
			inner = inner->next;
		}
		outer->pre_index = index;
		outer = outer->next;
	}
}

void		medium(t_stack_node **a, t_stack_node **b)
{
	if (!*a)
		return;
	if (stack_len(*a) < 2)
		return ;
	if (is_sorted(*a))
		return ;
	pre_index(a);
	push_chunks(a, b);
	push_back(a, b);
}