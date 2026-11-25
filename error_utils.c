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
#include <stdlib.h>
#include <stdio.h>

int		error_syntax(char *str_nbr);
int		error_repetition(t_stack_node *a, int nbr);
void	free_stack(t_stack_node **stack);
void	free_matrix(char **argv);
void	error_free(t_stack_node **a, char **argv, bool flag_argc_2);

void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_matrix(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = -1;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr -> next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *str_nbr)
{
	int	i;

	i = 0;
	if (!(str_nbr[i] == '+' || str_nbr[i] == '-'
			|| (str_nbr[i] >= '0' && str_nbr[i] <= '9')))
		return (1);
	if ((str_nbr[i] == '+' || str_nbr[i] == '-'))
		i++;
	while (str_nbr[i])
	{
		if (!(str_nbr[i] >= '0' && str_nbr[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
