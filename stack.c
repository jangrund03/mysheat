/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:59:37 by jagrund           #+#    #+#             */
/*   Updated: 2026/11/08 18:56:02 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int cap)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (s == NULL)
		return (NULL);
	s->data = malloc (sizeof(int) * cap);
	if (!s->data)
	{
		free(s);
		return (NULL);
	}
	s->cap = cap;
	s->size = 0;
	return (s);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	free (s->data);
	free (s);
}
