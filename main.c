#include "push_swap.h"
#include <stdio.h>

// Helper function to print the stack (using standard printf for testing)
void	print_stack(t_stack_node *stack, char *name)
{
	printf("%s: ", name);
	if (!stack)
	{
		printf("(empty)\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack_node	*stack_a;
	int				i;
	int				test_values[] = {3, 5, 1, 4, 2};

	stack_a = NULL;
	i = 0;

	// 1. Initialize the stack with test values
	while (i < 5)
	{
		append_node(&stack_a, test_values[i]);
		i++;
	}

	// 2. Print the initial state
	print_stack(stack_a, "Before Sort");

	// 3. Call your sorting function
	ft_sort_simple(&stack_a);

	// 4. Print the final state
	print_stack(stack_a, "After Sort ");

	// 5. Verify using your is_sorted function
	if (is_sorted(stack_a))
		printf("✅ SUCCESS: The stack is perfectly sorted!\n");
	else
		printf("❌ FAILURE: The stack is NOT sorted.\n");

	// 6. Free the memory to prevent leaks
	free_stack(&stack_a);
	return (0);
}