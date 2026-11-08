/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:27:37 by jagrund           #+#    #+#             */
/*   Updated: 2026/11/08 17:03:39 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*data;
	int	cap;
	int	size;
}	t_stack;

typedef struct s_ctx
{
	t_stack	*a;
	t_stack	*b;
	int		count[11];
	int		bench;
}	t_ctx;

void	sa(t_ctx *c);
void	sb(t_ctx *c);
void	ss(t_ctx *c);
void	pa(t_ctx *c);
void	pb(t_ctx *c);
void	ra(t_ctx *c);
void	rb(t_ctx *c);
void	rr(t_ctx *c);
void	rra(t_ctx *c);
void	rrb(t_ctx *c);
void	rrr(t_ctx *c);
int		stack_size(t_stack *s);
int		stack_at(t_stack *s, int pos);

#endif
