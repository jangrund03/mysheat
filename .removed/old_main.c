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

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				algo;
	int				arg_start;
	int				remaining;
	char			**split;

	a = NULL;
	b = NULL;
	algo = 0;
	arg_start = 1;
	if (argc < 2 && !argv)
		return (0);
	if (!ft_strcmp(argv[1], "--bench"))
	{
		algo = 1;
		arg_start = 2;
	}	if (!ft_strcmp(argv[1], "--simple"))
	{
		algo = 2;
		arg_start = 2;
	}
	else if (!ft_strcmp(argv[1], "--medium"))
	{
		algo = 3;
		arg_start = 2;
	}
	else if (!ft_strcmp(argv[1], "--complex"))
	{
		algo = 4;
		arg_start = 2;
	}
	else if (!ft_strcmp(argv[1], "--adaptive"))
	{
		algo = 5;
		arg_start = 2;
	}
	remaining = argc - arg_start;
	if (remaining <= 0)
		return (0);
	if (remaining == 1)
	{
		split = ft_split(argv[arg_start], ' ');
		stack_init(&a, split + 1, true);
	}
	else
		stack_init(&a, argv + arg_start, false);
	if (stack_len(a) >= 2)
	{
		if (algo == 1)
		{
			write(1, "gotta make the --bench\n", 23);
			free_stack(&a);
			free_stack(&b);
			return (0);
		}
		else if (algo == 2)
			simple(&a, &b);
		else if (algo == 3)
			medium(&a, &b);
		else if (algo == 4)
			complex(&a, &b);
		else
			adaptive(&a, &b);
	}
	// if (is_sorted(a) && !b)
	// 	fprintf(stderr, "OK\n");
	// else
	// 	fprintf(stderr, "KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}