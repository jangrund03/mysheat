/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havu <havu@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:51:07 by havu              #+#    #+#             */
/*   Updated: 2026/11/25 15:51:38 by havu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void			append_node(t_stack_node **stack, int numb);
t_stack_node	*find_last_node(t_stack_node *head);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*tmp;

	if (!(stack))
		return (1);
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
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
	node->next = NULL;
	node->value = numb;
	node->cheapest = false;
	node->above_median = false;
	node->target_node = NULL;
	node->current_position = 0;
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
