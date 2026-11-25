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

void		stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
static long	ft_atol(const char *str);

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	stack_init(t_stack_node **a, char **av, bool flag_argc_2)
{
	long	numb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_argc_2);
		numb = ft_atol(av[i]);
		if (numb > INT_MAX || numb < INT_MIN)
			error_free(a, av, flag_argc_2);
		if (error_repetition(*a, (int)numb))
			error_free(a, av, flag_argc_2);
		append_node(a, (int)numb);
		i++;
	}
	if (flag_argc_2)
		free_matrix(av);
}
