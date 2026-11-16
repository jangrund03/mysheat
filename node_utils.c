#include "push_swap.h"
#include <limits.h>

void	append_node(t_stack_node **stack, int numb);
t_stack_node	*find_last_node(t_stack_node *head);

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL)
	while (head -> next)
		head = head -> next;
	return (head);
}
void	append_node(t_stack_node **stack, int numb)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node -> value = numb;
	node -> next = NULL;
	if (!*stack)
	{
		*stack = node;
		node -> prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last -> next = node;
		node -> prev = last;
	}
}