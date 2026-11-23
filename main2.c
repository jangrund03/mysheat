#include "push_swap.h"


// get_flag: vrací kód strategie podle prvního argumentu (--bench=1,
// --simple=2, --medium=3, --complex=4, --adaptive=5, jinak 0).
// Důvod: původní řetěz if/else if v main() byl moc dlouhý pro Normu
// (max 25 řádků), tak je přesunutý sem a main() ho jen zavolá.
// Nenulový výsledek = argument byl flag, čísla začínají od argv[2].
// Checkni zda takhle dobrý, a kdyžtak to použijem

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
	return (0);
}

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
	if (argc < 2)
		return (0);

    algo = get_flag(argv[1]);
    if (algo != 0)
	    arg_start = 2;

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