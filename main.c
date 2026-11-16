# include <stdio.h>
#include "push_swap.h"

int main (int ac,char **av)
{
	(void)ac;
	int a;
	int i = 0;
	a =  count_words(av[1], ' ');
	printf("%d\n", a);
	av = ft_split(av[1], ' ');

	while(av[++i])
		printf("%s\n",av[i]);
}