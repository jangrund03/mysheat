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

void	adaptive(t_stack_node **a, t_stack_node **b);

void	adaptive(t_stack_node **a, t_stack_node **b)
{
	double	dis;

	dis = compute_disorder(*a);
	if (dis < 0.2)
		simple(a, b);
	else if (dis < 0.5)
		medium(a, b);
	else
		complex(a, b);
}
