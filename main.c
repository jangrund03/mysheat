#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to print the stack
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

// Helper function to run a single test case
void	run_test(int *values, int size)
{
	t_stack_node	*stack_a = NULL;
	t_stack_node	*stack_b = NULL;
	int				i = 0;

	// 1. Initialize stack A
	while (i < size)
	{
		append_node(&stack_a, values[i]);
		i++;
	}

	// 2. Print initial state
	print_stack(stack_a, "Before");
	printf("Stack B: (empty)\n\n");

	// 3. Run the function
	handle_five(&stack_a, &stack_b);

	// 4. Print final state
	print_stack(stack_a, "After ");
	print_stack(stack_b, "Stack B");

	// 5. Verify
	if (is_sorted(stack_a) && stack_b == NULL)
		printf("✅ SUCCESS: Stack is perfectly sorted and B is empty!\n");
	else
		printf("❌ FAILURE: Stack is not sorted or B is not empty.\n");

	printf("--------------------------------------------------\n\n");

	// 6. Free memory
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(void)
{
	// Test Case 1: Random Order
	int	test1[] = {3, 5, 1, 4, 2};
	printf("--- TEST 1: Random Order ---\n");
	run_test(test1, 5);

	// Test Case 2: Already Sorted
	int	test2[] = {1, 2, 3, 4, 5};
	printf("--- TEST 2: Already Sorted ---\n");
	run_test(test2, 5);

	// Test Case 3: Reverse Sorted
	int	test3[] = {5, 4, 3, 2, 1};
	printf("--- TEST 3: Reverse Sorted ---\n");
	run_test(test3, 5);

	// Test Case 4: Smallest at Bottom
	int	test4[] = {2, 3, 4, 5, 1};
	printf("--- TEST 4: Smallest at Bottom ---\n");
	run_test(test4, 5);

	return (0);
}