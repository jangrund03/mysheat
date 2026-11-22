#include "push_swap.h"
#include <stdio.h>
#include <string.h>

/*
** Optional algorithm keyword as first argument:
**   simple  -> simple()     (bubble sort)
**   medium  -> medium()     (chunk sort)
**   tiny    -> tiny_sort()  (ONLY correct for <= 3 elements)
**   (none)  -> push_swap()  (complex / turk-style)
**
** Examples:
**   ./push_swap 3 1 2
**   ./push_swap "5 4 3 2 1"
**   ./push_swap medium 4 67 3 87 23 1 99
**   ./push_swap simple 1 2 3 4 5
**   ./push_swap tiny 3 1 2
**
** Operations go to stdout; OK/KO to stderr.
*/

int	main(int argc, char **argv)
{
	t_stack_node	*a = NULL;
	t_stack_node	*b = NULL;
	int				algo = 0;      /* 0 = complex, 1 = simple, 2 = medium, 3 = tiny */
	int				arg_start = 1;
	int				remaining;
	char			**split;

	if (argc < 2)
		return (0);

	if (!strcmp(argv[1], "simple"))
		{ algo = 1; arg_start = 2; }
	else if (!strcmp(argv[1], "medium"))
		{ algo = 2; arg_start = 2; }
	else if (!strcmp(argv[1], "tiny"))
		{ algo = 3; arg_start = 2; }

	remaining = argc - arg_start;
	if (remaining <= 0)
		return (0);

	/* One arg left -> it's a quoted list, split it.
	** Otherwise the remaining argv entries are the numbers.
	** ft_split returns a vector whose [0] is an empty header,
	** so we skip it (split + 1) and free_matrix() will free
	** the base with free(argv - 1). */
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
			simple(&a);
		else if (algo == 2)
			medium(&a, &b);
		else if (algo == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}

	if (is_sorted(a) && !b)
		fprintf(stderr, "OK\n");
	else
		fprintf(stderr, "KO\n");

	free_stack(&a);
	free_stack(&b);
	return (0);
}