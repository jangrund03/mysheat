/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:19:20 by jagrund           #+#    #+#             */
/*   Updated: 2026/11/19 21:58:28 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack_node *stack)
{
	t_stack_node	*i;
	t_stack_node	*j;
	double			mistake;
	double			pair;

	pair = 0;
	mistake = 0;
	if (!(stack))
		return (0);
	i = stack;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			pair++;
			if (i->value > j->value)
				mistake++;
			j = j->	next;
		}
		i = i->next;
	}
	if (pair == 0)
		return (0);
	return (mistake / pair);
}
