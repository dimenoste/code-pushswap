/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insertion_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:44:39 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/02 17:06:54 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"


static int		g_tests_passed = 0;
static int		g_tests_failed = 0;
static size_t	g_total_ops = 0;

// void	print_test_result(const char *test_name, int passed)
// {
// 	if (passed)
// 	{
// 		printf("%s[PASS]%s %s\n", GREEN, NC, test_name);
// 		g_tests_passed++;
// 	}
// 	else
// 	{
// 		printf("%s[FAIL]%s %s\n", RED, NC, test_name);
// 		g_tests_failed++;
// 	}
// }
void	print_test_result(const char *test_name, int passed)
{
	if (passed)
	{
		printf("%s[✓]%s %s\n", GREEN, NC, test_name);
		g_tests_passed++;
	}
	else
	{
		printf("%s[✗]%s %s\n", RED, NC, test_name);
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
void	print_ops_count(t_op_list *ops, const char *label)
{
	printf("%s[INFO]%s %s -> %zu opérations\n", BLUE, NC, label, ops->count);
}
void	test_isort_case(long *vals, int count, const char *label)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;



	a = make_stack(vals, count, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);

	printf("%s -> sorted (%zu ops)\n", label, ops->count);
	print_test_result("is in order ?", is_in_order(a) && is_empty_stack(b));
	print_ops_count(ops, label); // affichage des opérations
	g_total_ops += ops->count;   // <- ajoute au total global
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}

void	test_sort_three_case(long *vals, const char *label, int max_ops)
{
	t_stack		*a;
	t_op_list	*ops;

	a = make_stack(vals, 3, A);
	ops = new_op_list();
	sort_three(a, ops);
	printf("%s -> sorted, ops<=%d (got %zu)", label, max_ops,
		ops->count);
	print_test_result("Is sorted for three", is_in_order(a) && (int)ops->count <= max_ops);
	clear_stack(&a);
	clear_op_list(&ops);
}

void	test_sort_two(void)
{
	long	v1[] = {5, 3};
	long	v2[] = {3, 5};

	printf("\n%s=== TEST: sort_two ===%s\n", YELLOW, NC);
	test_isort_case(v1, 2, "n=2 [5,3]");
	test_isort_case(v2, 2, "n=2 [3,5]");
}

void	test_sort_three(void)
{
	long	c1[] = {1, 2, 3};
	long	c2[] = {2, 1, 3};
	long	c3[] = {3, 1, 2};
	long	c4[] = {2, 3, 1};
	long	c5[] = {3, 2, 1};
	long	c6[] = {1, 3, 2};

	printf("\n%s=== TEST: sort_three (6 permutations) ===%s\n", YELLOW, NC);
	test_sort_three_case(c1, "[1,2,3]", 0);
	test_sort_three_case(c2, "[2,1,3]", 1);
	test_sort_three_case(c3, "[3,1,2]", 1);
	test_sort_three_case(c4, "[2,3,1]", 1);
	test_sort_three_case(c5, "[3,2,1]", 2);
	test_sort_three_case(c6, "[1,3,2]", 2);
}

void	test_insertion_sort_basic(void)
{
	long	v1[] = {42};
	long	v4[] = {4, 2, 3, 1};
	long	v5[] = {5, 1, 4, 2, 3};

	printf("\n%s=== TEST: insertion_sort (basic) ===%s\n", YELLOW, NC);
	test_isort_case(v1, 1, "n=1 [42]");
	test_isort_case(v4, 4, "n=4 [4,2,3,1]");
	test_isort_case(v5, 5, "n=5 [5,1,4,2,3]");
}

void	test_insertion_sort_edge_cases(void)
{
	long	v_rev[] = {5, 4, 3, 2, 1};
	long	v_neg[] = {-2147483648, 2147483647, 0, -1, 1};

	printf("\n%s=== TEST: insertion_sort (edge) ===%s\n", YELLOW, NC);
	test_isort_case(v_rev, 5, "reversed [5..1]");
	test_isort_case(v_neg, 5, "[INT_MIN,INT_MAX,0,-1,1]");
}

void	test_insertion_sort_medium(void)
{
	long	v10[] = {7, 3, 9, 1, 5, 8, 2, 10, 4, 6};
	long	v20[] = {17, 3, 12, 8, 20, 1, 15, 6, 11, 19, 4, 14, 9, 2, 18, 7, 13,
			5, 16, 10};

	printf("\n%s=== TEST: insertion_sort (medium) ===%s\n", YELLOW, NC);
	test_isort_case(v10, 10, "n=10 random");
	test_isort_case(v20, 20, "n=20 random");
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

void	test_insertion_sort_large(void)
{
	long	*v;
	int		sizes[] = {100, 500};
	int		i;
	char	label[64];

	printf("\n%s=== TEST: insertion_sort (large) ===%s\n", YELLOW, NC);
	i = 0;
	while (i < 2)
	{
		v = malloc(sizeof(long) * sizes[i]);
		if (!v)
			return ;
		srand(42 + i);
		fill_random_unique(v, sizes[i]);
		printf(label, sizeof(label), "n=%d random", sizes[i]);
		test_isort_case(v, sizes[i], label);
		free(v);
		i++;
	}
}

void	test_ops_output(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	long		vals[] = {3, 2, 1};

	printf("\n%s=== TEST: operations output ===%s\n", YELLOW, NC);
	a = make_stack(vals, 3, A);
	b = new_stack(B);
	ops = new_op_list();
	insertion_sort(a, b, ops);
	printf("  Operations for [3,2,1]: ");
	print_operations(ops);
	print_test_result("result is sorted", is_in_order(a));
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
}

int	main(void)
{
	printf("%s", BLUE);
	printf("==================================================\n");
	printf("       INSERTION SORT - Test Suite                 \n");
	printf("       Cost-optimized with rr/rrr                 \n");
	printf("==================================================\n");
	printf("%s\n", NC);
	test_sort_two();
	test_sort_three();
	test_insertion_sort_basic();
	test_insertion_sort_edge_cases();
	test_insertion_sort_medium();
	test_insertion_sort_large();
	test_ops_output();
	printf("\n%s", BLUE);
	printf("==================================================\n");
	printf("              Test Results                         \n");
	printf("--------------------------------------------------\n");
	printf("  %sPassed: %d%s\n", GREEN, g_tests_passed, BLUE);
	printf("  %sFailed: %d%s\n", RED, g_tests_failed, BLUE);
	printf("==================================================\n");
	printf("%s\n", NC);
	printf("%s[INFO]%s Total opérations insertion_sort : %zu\n", BLUE, NC,
		g_total_ops);
	return (g_tests_failed != 0);
}
