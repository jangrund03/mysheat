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

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// split.c
char		**ft_split(char *str, char sep);
int			count_words(char *str, char sep);
// static char	*get_next_word(char *str, char sep);

void	sa(t_stack_node *c);
void	sb(t_stack_node *c);
void	ss(t_stack_node *c);
void	pa(t_stack_node *c);
void	pb(t_stack_node *c);
void	ra(t_stack_node *c);
void	rb(t_stack_node *c);
void	rr(t_stack_node *c);
void	rra(t_stack_node *c);
void	rrb(t_stack_node *c);
void	rrr(t_stack_node *c);


#endif
