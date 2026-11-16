#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	error_syntax(char *str_nbr);

int	error_syntax(char *str_nbr)
{
	int	i;

	i = 0;
	if(!(str_nbr[i] == '+' || str_nbr[i] == '-'
		|| (str_nbr[i] => '0' && str_nbr[i] <= '9')))
		return (1);
	if((str_nbr[i] == '+' || str_nbr[i] == '-'))
		i++;
	while(str_nbr[i])
	{
		if(!(str_nbr[i] => '0' && str_nbr[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}