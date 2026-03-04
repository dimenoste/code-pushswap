/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:34:30 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/03/03 15:39:19 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

static int	g_tests_passed = 0;
static int	g_tests_failed = 0;

/* ========== HELPERS ========== */

void	print_test_result(const char *test_name, int passed)
{
	if (passed)
	{
		printf("%s[PASS]%s %s\n", GREEN, NC, test_name);
		g_tests_passed++;
	}
	else
	{
		printf("%s[FAIL]%s %s\n", RED, NC, test_name);
		g_tests_failed++;
	}
}

t_stack	*make_stack(long *values, int count, t_stack_name name)
{
	t_stack	*stk;
	int		i;

	stk = new_stack(name);
	i = 0;
	while (i < count)
	{
		stack_add_back(stk, new_node(values[i]));
		i++;
	}
	return (stk);
}

void	fill_random_unique(long *arr, int size)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < size)
	{
		arr[i] = i + 1;
		i++;
	}
	i = size - 1;
		while (i > 0)
	{
		j = rand() % (i + 1);
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i--;
	}
}

/* Prints just the op count as a number, e.g. "5" */
void	print_op_count(t_op_list *ops)
{
	printf("%zu\n", ops->count);
}

/* ========== TEST: op_list recording & print_operations ========== */

void	test_op_list_output(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	long		vals[] = {3, 2, 1};

	printf("\n%s=== TEST: op_list recording ===%s\n", YELLOW, NC);
	a = make_stack(vals, 3, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	print_test_result("result is sorted", is_in_order(a));
	print_test_result("B is empty", is_empty_stack(b));
	print_test_result("ops were recorded", ops->count > 0);
	printf("  operations list:\n  ");
	print_operations(ops);
	printf("  op count: ");
	print_op_count(ops);
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}


/* ========== TEST: already sorted list ========== */

void	test_already_sorted(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	long		v2[] = {1, 2};
	long		v3[] = {1, 2, 3};
	long		v5[] = {1, 2, 3, 4, 5};
	long		v10[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("\n%s=== TEST: already sorted list ===%s\n", YELLOW, NC);
	/* n=2 sorted */
	a = make_stack(v2, 2, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	print_test_result("[1,2] stays sorted, 0 ops",
		is_in_order(a) && ops->count == 0);
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
	/* n=3 sorted */
	a = make_stack(v3, 3, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	print_test_result("[1,2,3] stays sorted, 0 ops",
		is_in_order(a) && ops->count == 0);
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
	/* n=5 sorted */
	a = make_stack(v5, 5, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	printf("  [1..5] sorted: ");
	print_op_count(ops);
	print_test_result("[1..5] result is sorted", is_in_order(a));
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
	/* n=10 sorted */
	a = make_stack(v10, 10, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	printf("  [1..10] sorted: ");
	print_op_count(ops);
	print_test_result("[1..10] result is sorted", is_in_order(a));
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}

/* ========== TEST: sort_two & sort_three ========== */

void	test_sort_small(void)
{
	long	c1[] = {1, 2, 3};
	long	c2[] = {2, 1, 3};
	long	c3[] = {3, 1, 2};
	long	c4[] = {2, 3, 1};
	long	c5[] = {3, 2, 1};
	long	c6[] = {1, 3, 2};
	long	v1[] = {5, 3};
	long	v2[] = {3, 5};

	printf("\n%s=== TEST: sort_two ===%s\n", YELLOW, NC);
	{
		t_stack *a = make_stack(v1, 2, A);
		t_stack *b = new_stack(B);
		t_op_list *ops = new_op_list();
		insertion_sort(a, b, ops);
		print_test_result("[5,3] -> sorted (1 op)",
			is_in_order(a) && ops->count == 1);
		clear_stack(&a); clear_stack(&b); clear_op_list(&ops);
	}
	{
		t_stack *a = make_stack(v2, 2, A);
		t_stack *b = new_stack(B);
		t_op_list *ops = new_op_list();
		insertion_sort(a, b, ops);
		print_test_result("[3,5] -> sorted (0 ops)",
			is_in_order(a) && ops->count == 0);
		clear_stack(&a); clear_stack(&b); clear_op_list(&ops);
	}
	printf("\n%s=== TEST: sort_three (6 permutations) ===%s\n", YELLOW, NC);
	{
		t_stack *a; t_op_list *ops;
		long *perms[] = {c1, c2, c3, c4, c5, c6};
		int max_ops[] = {0, 1, 1, 1, 2, 2};
		char *names[] = {"[1,2,3]", "[2,1,3]", "[3,1,2]",
			"[2,3,1]", "[3,2,1]", "[1,3,2]"};
		int i = 0;
		char msg[128];
		while (i < 6)
		{
			a = make_stack(perms[i], 3, A);
			ops = new_op_list();
			sort_three(a, ops);
			snprintf(msg, sizeof(msg), "%s -> sorted, ops<=%d (got %zu)",
				names[i], max_ops[i], ops->count);
			print_test_result(msg,
				is_in_order(a) && (int)ops->count <= max_ops[i]);
			clear_stack(&a);
			clear_op_list(&ops);
			i++;
		}
	}
}

/* ========== BENCH: print op count for a given input ========== */

size_t	bench_sort(long *vals, int count, const char *label)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	size_t		n_ops;

	a = make_stack(vals, count, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	n_ops = ops->count;
	print_test_result(label, is_in_order(a) && is_empty_stack(b));
	printf("  %s ops: ", label);
	print_op_count(ops);
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
	return (n_ops);
}

/* ========== TEST: 100 random unique ints ========== */

void	test_100_random(void)
{
	long	*arr;

	printf("\n%s=== BENCH: 100 random unique ints ===%s\n", YELLOW, NC);
	arr = malloc(sizeof(long) * 100);
	if (!arr)
		return ;
	fill_random_unique(arr, 100);
	bench_sort(arr, 100, "n=100");
	free(arr);
}

/* ========== TEST: 500 random unique ints ========== */

void	test_500_random(void)
{
	long	*arr;


	printf("\n%s=== BENCH: 500 random unique ints ===%s\n", YELLOW, NC);
	arr = malloc(sizeof(long) * 500);
	if (!arr)
		return ;
	fill_random_unique(arr, 500);
	bench_sort(arr, 500, "n=500");
	free(arr);
}

void	print_disorder(t_stack *a)
{
	float		disorder;

	disorder = compute_disorder(a);
	printf("  disorder: %.1f%%\n", disorder * 100);
}
/* ========== VISUAL: step-by-step sort display ========== */

void	test_visual_sort(void)
{

	long	vals[10];
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	t_cost		best;

	printf("\n%s=== VISUAL: insertion sort step by step ===%s\n", YELLOW, NC);
	fill_random_unique(vals, 10);
	a = make_stack(vals, 10, A);
	b = new_stack(B);
	ops = new_op_list();
	/* Phase 1: avant tri */
	printf("\n%s--- AVANT TRI ---%s\n", BLUE, NC);
	print_stack(a, "A");
	print_disorder(a);
	/* Phase 2: assign indices + push to B */
	assign_indices(a);
	while (a->length > 3)
	{
		best = find_cheapest(a, b);

		//print_stack(a, "A");
		execute_rotations(a, b, ops, &best);
		print_stack(b, "B");
		push(a, b, ops);
		//print_stack(b, "B");
	}

	printf("\n%s--- APRES PUSH VERS B ---%s\n", BLUE, NC);

	//print_operations(ops);
	print_stack(a, "A");
	/* Phase 3: sort remaining 3 + push back */
	sort_three(a, ops);

	print_operations(ops);
	print_stack(b, "B");
	push_all_to_a(a, b, ops);

	print_operations(ops);
	printf("\n%s--- RESULTAT FINAL ---%s\n", BLUE, NC);
	print_stack(a, "A");

	print_stack(b, "B");
	printf("total ops: ");
	print_op_count(ops);
	//print_operations(ops);
	print_test_result("La liste a ete triee",
		is_in_order(a) && is_empty_stack(b));
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}

/* ========== TEST: basic & edge cases ========== */

void	test_basic_cases(void)
{
	long	v1[] = {42};
	long	v4[] = {4, 2, 3, 1};
	long	v5[] = {5, 1, 4, 2, 3};
	long	v_rev[] = {5, 4, 3, 2, 1};
	long	v_neg[] = {-2147483648, 2147483647, 0, -1, 1};

	printf("\n%s=== TEST: basic cases ===%s\n", YELLOW, NC);
	bench_sort(v1, 1, "n=1 [42]");
	bench_sort(v4, 4, "n=4 [4,2,3,1]");
	bench_sort(v5, 5, "n=5 [5,1,4,2,3]");
	printf("\n%s=== TEST: edge cases ===%s\n", YELLOW, NC);
	bench_sort(v_rev, 5, "reversed [5..1]");
	bench_sort(v_neg, 5, "[INT_MIN,INT_MAX,0,-1,1]");
}

/* ========== MAIN ========== */

int	main(void)
{
	srand((unsigned int)(time(NULL) ^ getpid()));
	printf("%s", BLUE);
	printf("==================================================\n");
	printf("       INSERTION SORT - Test Suite                 \n");
	printf("       Cost-optimized with rr/rrr                 \n");
	printf("==================================================\n");
	printf("%s\n", NC);
	test_op_list_output();
	test_already_sorted();
	test_sort_small();
	test_basic_cases();
	test_100_random();
	test_500_random();
	test_visual_sort();
	printf("\n%s", BLUE);
	printf("==================================================\n");
	printf("              Test Results                         \n");
	printf("--------------------------------------------------\n");
	printf("  %sPassed: %d%s\n", GREEN, g_tests_passed, BLUE);
	printf("  %sFailed: %d%s\n", RED, g_tests_failed, BLUE);
	printf("==================================================\n");
	printf("%s\n", NC);
	return (g_tests_failed != 0);
}
