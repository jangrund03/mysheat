/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:27:37 by jagrund           #+#    #+#             */
/*   Updated: 2026/11/19 20:33:15 by jagrund          ###   ########.fr       */
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
	int					pre_index;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// adaptive.c
void			adaptive(t_stack_node **a, t_stack_node **b);

// complex.c
void			complex(t_stack_node **a, t_stack_node **b);
// static void	move_nodes(t_stack_node **a, t_stack_node **b);
// static void	rotate_both(t_stack_node **a, t_stack_node **b,
// 						t_stack_node *cheapest_node);
// static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
// 						t_stack_node *cheapest_node);

// medium.c
void			medium(t_stack_node **a, t_stack_node **b);
// static void	pre_index(t_stack_node **stack);
// static int	chunk_siz(int size);
// static void	push_chunks(t_stack_node **a, t_stack_node **b);
// static void	push_back(t_stack_node **a, t_stack_node **b);

// simple.c
void			simple(t_stack_node **stack, t_stack_node **empty);
// static int	bubble_pass(t_stack_node **a);

// tiny_sort.c
void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_highest(t_stack_node *stack);

// push_swap_commands.c
void			finish_rotation(t_stack_node **s, t_stack_node *top, char here);

// push_swap_init.c
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
// static void	set_target_node(t_stack_node *a, t_stack_node *b);

// error_utils.c
int				error_syntax(char *str_nbr);
int				error_repetition(t_stack_node *a, int nbr);
void			free_stack(t_stack_node **stack);
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);

// stack_init.c
void			stack_init(t_stack_node **a, char **av, bool flag_argc_2);
// static long	ft_atol(const char *str);

// node_utils.c
void			append_node(t_stack_node **stack, int numb);
t_stack_node	*find_last_node(t_stack_node *head);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);

// split.c
char			**ft_split(char *str, char sep);
int				count_words(char *str, char sep);
// static char	*get_next_word(char *str, char sep);

// rotate_command.c
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
// static void	rotate(t_stack_node **stack);

// swap_command.c
void			sa(t_stack_node	**a, bool checker);
void			sb(t_stack_node	**b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
// static void	swap(t_stack_node **head);

// rev_rotate_command.c
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
// static void	reverse_rotate(t_stack_node **stack);

// push_command.c
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
// static void	push(t_stack_node **src, t_stack_node **dest);

// disorder.c
double			compute_disorder(t_stack_node *stack);

// ft_strcmp.c
int				ft_strcmp(char *s1, char *s2);

#endif
