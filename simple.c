#include "push_swap.h"

static int	bubble_pass(t_stack_node **a);
void		ft_sort_simple(t_stack_node **stack);
int			find_min_val(t_stack_node **a);
int			find_min_pos(t_stack_node **a, int min);
static void	rotate_min_to_top(t_stack_node **a);

int	find_min_pos(t_stack_node **a, int min)
{
	int				pos;
	t_stack_node	*tmp;

	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value == min)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int		find_min_val(t_stack_node **a)
{
	t_stack_node	*tmp;
	int				val;

	tmp = *a;
	val = tmp->value;
	while (tmp)
	{
		if (tmp->value < val)
			val = tmp->value;
		tmp = tmp->next;
	}
	return (val);
}

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

static void	rotate_min_to_top(t_stack_node **a)
{
	int	min_val;
	int	min_pos;
	int	size;

	min_val = find_min_val(a);
	min_pos = find_min_pos(a, min_val);
	size = stack_len(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, false);
	}
	else
	{
		while (size-- > min_pos)
			rra(a, false);
	}
}

void	ft_sort_simple(t_stack_node **stack)
{
	int	swapped;

	swapped = 1;
	if (stack_len(*stack) < 2)
		return ;
	if (is_sorted(*stack))
		return ;
	while (swapped)
		swapped = bubble_pass(stack);
	rotate_min_to_top(stack);
}
