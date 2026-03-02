/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:12:31 by mberraho          #+#    #+#             */
/*   Updated: 2026/03/01 16:39:25 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === TESTS DES ALGO ET FONCTIONS ASSOCIEES ===================
#include "push_swap.h"
#include <stdio.h>
#include <string.h>

/* Utilisation de macros pour l'outpur*/
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

/* Test counter */
static int	g_tests_passed = 0;
static int	g_tests_failed = 0;

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
void	test_find_min_pos(void)
{
	t_stack	*a;
	t_bool	res;
	size_t	pos_min;
	t_node	*ptr_min;

	printf("============= TEST medium_algo.c: find_min_pos ==================\n");
	a = new_stack(A);
	stack_add_back(a, new_node(8));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(4));
	stack_add_back(a, new_node(-5));
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(0));
	stack_add_back(a, new_node(-1));
	stack_add_back(a, new_node(9));
	stack_add_back(a, new_node(1));
	ptr_min = a->head;
	// 4 is the position starting at 1 of the minimum
	pos_min = find_min_ptr_pos(a, &ptr_min);
	res = ((int)pos_min == 6);
	print_test_result("is minimum found at right position \n", FALSE == res);
	res = ((int)pos_min == -1);
	print_test_result("is minimum found at right position \n", FALSE == res);
	res = ((int)pos_min == 0);
	print_test_result("is minimum found at right position \n", FALSE == res);
	res = ((int)pos_min == 4);
	print_test_result("is minimum found at right position \n", TRUE == res);
	// get the min node
	print_test_result("correct minimum value ? \n", ptr_min->value == -5);
	print_test_result("correct next element ?  \n", ptr_min->next->value == 5);
	print_test_result("correct previous element ? \n",
		ptr_min->previous->value == 4);
	print_stack(a, "A");
	clear_stack(&a);
	printf("======================================================================\n\n");
}

void	test_is_sorted_circular(void)
{
	t_stack	*a;
	t_stack	*b;
	t_bool	res;

	printf("============= TEST medium_algo.c: is_sorted_circular ==================\n");
	// Non Sorted
	a = new_stack(A);
	stack_add_back(a, new_node(8));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(4));
	stack_add_back(a, new_node(-5));
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(0));
	stack_add_back(a, new_node(-1));
	stack_add_back(a, new_node(9));
	stack_add_back(a, new_node(1));
	res = is_sorted_circular(a);
	print_test_result("is stack circularly sorted ?\n", FALSE == res);
	print_stack(a, "A");
	clear_stack(&a);
	// Sorted
	b = new_stack(A);
	stack_add_back(b, new_node(564));
	stack_add_back(b, new_node(15164));
	stack_add_back(b, new_node(-1));
	stack_add_back(b, new_node(2));
	stack_add_back(b, new_node(3));
	res = is_sorted_circular(b);
	print_test_result("is stack circularly sorted ?\n", TRUE == res);
	print_stack(b, "A");
	clear_stack(&b);
	printf("======================================================================\n\n");
}

int	main(void)
{
	printf("%s", BLUE);
	printf("╔════════════════════════════════════════════════╗\n");
	printf("║        PUSH SWAP - Test Suite                  ║\n");
	printf("║        ALGORITHMS                              ║\n");
	printf("╚════════════════════════════════════════════════╝\n");
	printf("%s\n", NC);
	/* Call tests functions*/
	test_find_min_pos();
	test_is_sorted_circular();
	algo_lis();
	printf("\n%s", BLUE);
	printf("╔════════════════════════════════════════════════╗\n");
	printf("║              Test Results                      ║\n");
	printf("╠════════════════════════════════════════════════╣\n");
	printf("║  %sPassed: %2d%s                                    ║\n", GREEN,
		g_tests_passed, BLUE);
	printf("║  %sFailed: %2d%s                                    ║\n", RED,
		g_tests_failed, BLUE);
	printf("╚════════════════════════════════════════════════╝\n");
	printf("%s\n", NC);
	return (g_tests_failed == 0 ? 0 : 1);
}