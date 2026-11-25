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

static void	push(t_stack_node **src, t_stack_node **dest);
void		pa(t_stack_node **a, t_stack_node **b, bool checker);
void		pb(t_stack_node **b, t_stack_node **a, bool checker);

static void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*to_push;
	t_stack_node	*new_head;

	if (!dest || !src || !*src)
		return ;
	to_push = *src;
	new_head = to_push->next;
	*src = new_head;
	if (new_head)
		new_head->prev = NULL;
	to_push->prev = NULL;
	to_push->next = *dest;
	if (*dest)
		(*dest)->prev = to_push;
	*dest = to_push;
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}
