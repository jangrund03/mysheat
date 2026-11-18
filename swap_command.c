#include "push_swap.h"

static void swap(t_stack_node **head);
void	sb(t_stack_node	**a, bool checker);
void	sb(t_stack_node	**b, bool checker);
void	ss(t_stack_node **a, t_stack_node **b, bool checker);

static void swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!head || !*head || !(*head)->next)
		return ;

	first  = *head;
	second = first->next;
	third  = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev  = second;
	first->next  = third;
	if (third)
		third->prev = first;
	*head = second;
}

void	sa(t_stack_node	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node	**b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}