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

#include "push_swap.h"

static void		choose_algo(t_stack_node **a, t_stack_node **b, int algo);
static void		init_main(t_stack_node **a, t_stack_node **b,
					int *algo, int *arg_start);
static int		get_flag(char *arg);
void			free_stacks(t_stack_node **a, t_stack_node **b);

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				algo;
	int				arg_start;
	char			**split;

	init_main(&a, &b, &algo, &arg_start);
	if (argc < 2)
		return (0);
	algo = get_flag(argv[1]);
	if (algo != 0)
		arg_start = 2;
	if (argc - arg_start <= 0)
		return (0);
	if (argc - arg_start == 1)
	{
		split = ft_split(argv[arg_start], ' ');
		stack_init(&a, split + 1, true);
	}
	else
		stack_init(&a, argv + arg_start, false);
	if (stack_len(a) >= 2)
		choose_algo(&a, &b, algo);
	free_stacks(&a, &b);
	return (0);
}

void	free_stacks(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
}

static int	get_flag(char *arg)
{
	if (!ft_strcmp(arg, "--bench"))
		return (1);
	else if (!ft_strcmp(arg, "--simple"))
		return (2);
	else if (!ft_strcmp(arg, "--medium"))
		return (3);
	else if (!ft_strcmp(arg, "--complex"))
		return (4);
	else if (!ft_strcmp(arg, "--adaptive"))
		return (5);
	else
		return (0);
}

static void	init_main(t_stack_node **a, t_stack_node **b,
				int *algo, int *arg_start)
{
	*a = NULL;
	*b = NULL;
	*algo = 0;
	*arg_start = 1;
}

static void	choose_algo(t_stack_node **a, t_stack_node **b, int algo)
{
	if (algo == 1)
	{
		write(1, "gotta make the --bench\n", 23);
		free_stack(a);
		free_stack(b);
	}
	else if (algo == 2)
		simple(a, b);
	else if (algo == 3)
		medium(a, b);
	else if (algo == 4)
		complex(a, b);
	else
		adaptive(a, b);
}
