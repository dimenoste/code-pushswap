#include "push_swap.h"

typedef void	(*rotate_f)(t_stack *stack, t_op_list *ops);

// function to find where is the minimum position of the stack list
// 0 indexed value (index 0). Position is from 1 to len of stack
// pass a ptr to node by adress to get the min node
size_t	find_min_ptr_pos(t_stack *stk, t_node **ptr_min)
{
	size_t	i;
	size_t	j;
	t_node	*ptr_node;
	int		min;

	if (stk->length == 0)
		return (0);
	i = 1;
	j = i;
	ptr_node = stk->head;
	*ptr_min = ptr_node;
	min = ptr_node->value;
	while (i <= stk->length)
	{
		if (ptr_node->value < min)
		{
			min = ptr_node->value;
			*ptr_min = ptr_node;
			j = i;
		}
		ptr_node = ptr_node->next;
		i++;
	}
	return (j);
}

size_t	get_max_index(t_stack *stk)
{
	size_t	i;
	t_node	*ptr_node;
	size_t	max;

	if (stk->length == 0)
		return (0);
	i = 0;
	ptr_node = stk->head;
	max = ptr_node->index;
	while (i < stk->length)
	{
		if (ptr_node->index > max)
			max = ptr_node->index;
		ptr_node = ptr_node->next;
		i++;
	}
	return (max);
}

int	is_sorted_circular(t_stack *stk)
{
	int		is_sorted;
	t_node	*ptr_min;
	t_node	*head_orig;

	is_sorted = 0;
	head_orig = stk->head;
	ptr_min = stk->head;
	find_min_ptr_pos(stk, &ptr_min);
	stk->head = ptr_min;
	is_sorted = is_in_order(stk);
	// printf("result is in order (1 for order or empty) : %d\n", is_sorted);
	// print_stack(stk, "a should be in order");
	stk->head = head_orig; // reset the head at the original node
	// print_stack(stk, "a should be like before");
	return (is_sorted);
}
void	rotate_until_sorted(t_stack *stk, t_op_list *ops)
{
	size_t		pos_min;
	t_node		*ptr_min;
	rotate_f	rot;
	size_t		nb_rotate;

	if (!stk || !stk->head || stk->length < 2 || !is_sorted_circular(stk))
	{
		// printf("error\n");
		return ;
	}
	// print_stack(stk, "A from rotate until sorted");
	ptr_min = stk->head;
	pos_min = find_min_ptr_pos(stk, &ptr_min);
	// printf("pos min %zu\n", pos_min);
	if (pos_min == 0)
	// pos min should be from 1 to len of stack
	{
		// printf("error,
		// ptr should point to node with 0 index and min value\n");
		// printf("index found for the min is %zu\n", ptr_min->index);
		return ;
	}
	nb_rotate = 0;
	if (pos_min <= stk->length / 2)
	{
		rot = &rotate;
		nb_rotate = pos_min - 1;
	}
	else
	{
		rot = &reverse_rotate;
		nb_rotate = stk->length - pos_min + 1;
	}
	while (nb_rotate > 0)
	{
		rot(stk, ops);
		// print_stack(stk, "A from loop in rotate until sorted");
		nb_rotate--;
	}
	// print_stack(stk, "A should reotated ordered");
	return ;
}

void	algo_lis(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	size_t		len_a;
	size_t		max_a;
	int			nb_lis;

	printf("============= TEST medium_algo.c: algo_lis ==================\n");
	ops = new_op_list();
	// {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
	// 398 → 938 → 634 → 200 → 987 → 77 → 282 → 768 → 441 → 395
	a = new_stack(A);
	stack_add_back(a, new_node(398));
	stack_add_back(a, new_node(938));
	stack_add_back(a, new_node(634));
	stack_add_back(a, new_node(200));
	stack_add_back(a, new_node(987));
	stack_add_back(a, new_node(77));
	stack_add_back(a, new_node(282));
	stack_add_back(a, new_node(768));
	stack_add_back(a, new_node(441));
	stack_add_back(a, new_node(395));
	if (a->length < 2)
		return ;
	// add lis and index
	nb_lis = add_lis_to_nodes(a);
	printf("====");
	assign_indices(a);
	// create stack b
	b = new_stack(B);
	// printf("================================== set up data before sort ====================================\n\n");
	// print_stack(a, "A");
	// print_stack(b, "B");
	// print_index_stack(a, "A");
	// print_index_stack(b, "B");
	// print_lis_stack(a, "A");
	// print_lis_stack(b, "B");
	printf("================================== insert non lis dans B ====================================\n\n");
	// push all non lis elements to B
	len_a = a->length;
	while (a->length > 0 && nb_lis > 0)
	{
		if (a->head->is_lis == 0)
			push(a, b, ops);
		else
			rotate(a, ops);
	}
	printf("========================= after insert dans B ============================================\n\n");
	print_stack(a, "A");
	print_stack(b, "B");
	// print_lis_stack(a, "A");
	// print_lis_stack(b, "B");
	print_index_stack(a, "A");
	print_index_stack(b, "B");
	printf("========================= reinsertion dans A ============================================\n\n");
	// int i = 5;
	while (b->length > 0) // && i > 0)
	{
		printf("head of a %d\n", a->head->value);
		printf("head of b %d\n", b->head->value);
		print_index_stack(a, "A");
		print_index_stack(b, "B");
		max_a = get_max_index(a);
		if (max_a < b->head->index)
		{
			push(b, a, ops);
			rotate(a, ops);
			print_index_stack(a, " max_a < b->head->index A");
		}
		else
		{
			printf("=== START Rotate until sorted ==\n\n");
			rotate_until_sorted(a, ops);
			print_index_stack(a, "A should be sorted");
			printf("=== END Rotate until sorted ==\n\n");
			while (a->head->index < b->head->index)
			{
				print_index_stack(a, " a->head->index < b->head->index A");
				rotate(a, ops);
			}
			if (a->head->index > b->head->index)
			{
				push(b, a, ops);
				print_index_stack(a, " a->head->index > b->head->index A");
			}
		}
		printf("=== after poush from b to a ==\n\n");
		print_index_stack(a, "A");
		print_index_stack(b, "B");
		// i--;
	} //// print and clean
	printf("=== START Rotate until sorted ==\n\n");
	rotate_until_sorted(a, ops);
	print_index_stack(a, "A should be sorted");
	printf("=== END Rotate until sorted ==\n\n");
	printf("Number of ops :%zu\n", ops->count);
	printf("=====================================================================\n\n");
	print_stack(a, "A");
	print_stack(b, "B");
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
	printf("======================================================================\n\n");
}

// void	lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops)
// {
// 	size_t	len_a;
// 	size_t	max_a;

// 	len_a = a->length;
// 	if (len_a <= 1)
// 		return ;
// 	if (len_a == 2)
// 	{
// 		sort_two(a, ops);
// 		return ;
// 	}
// 	if (len_a == 3)
// 	{
// 		sort_three(a, ops); // petit tri hardcode
// 		return ;
// 	}
// 	// add lis and index
// 	add_lis_to_nodes(a);
// 	printf("====");
// 	assign_indices(a);
// 	// printf("================================== set up data before sort ====================================\n\n");
// 	// print_stack(a, "A");
// 	// print_stack(b, "B");
// 	// print_index_stack(a, "A");
// 	// print_index_stack(b, "B");
// 	// print_lis_stack(a, "A");
// 	// print_lis_stack(b, "B");
// 	// printf("================================== insert non lis dans B ====================================\n\n");
// 	// push all non lis elements to B
// 	while (len_a > 0)
// 	{
// 		if (a->head->is_lis == 0)
// 			push(a, b, ops);
// 		else
// 			rotate(a, ops);
// 		len_a--;
// 	}
// 	// printf("========================= after insert dans B ============================================\n\n");
// 	// print_stack(a, "A");
// 	// print_stack(b, "B");
// 	// // print_lis_stack(a, "A");
// 	// // print_lis_stack(b, "B");
// 	// print_index_stack(a, "A");
// 	// print_index_stack(b, "B");
// 	// printf("========================= reinsertion dans A ============================================\n\n");
// 	// int i = 5;
// 	while (b->length > 0) // && i > 0)
// 	{
// 		// printf("head of a %d\n", a->head->value);
// 		// printf("head of b %d\n", b->head->value);
// 		// print_index_stack(a, "A");
// 		// print_index_stack(b, "B");
// 		max_a = get_max_index(a);
// 		if (max_a < b->head->index)
// 		{
// 			push(b, a, ops);
// 			rotate(a, ops);
// 			print_index_stack(a, " max_a < b->head->index A");
// 		}
// 		else
// 		{
// 			// printf("=== START Rotate until sorted ==\n\n");
// 			rotate_until_sorted(a, ops);
// 			// print_index_stack(a, "A should be sorted");
// 			// printf("=== END Rotate until sorted ==\n\n");
// 			while (a->head->index < b->head->index)
// 			{
// 				// print_index_stack(a, " a->head->index < b->head->index A");
// 				rotate(a, ops);
// 			}
// 			if (a->head->index > b->head->index)
// 			{
// 				push(b, a, ops);
// 				// print_index_stack(a, " a->head->index > b->head->index A");
// 			}
// 		}
// 		// printf("=== after poush from b to a ==\n\n");
// 		// print_index_stack(a, "A");
// 		// print_index_stack(b, "B");
// 		// i--;
// 	}
// 	//// print and clean
// 	// printf("=== START Rotate until sorted ==\n\n");
// 	rotate_until_sorted(a, ops);
// 	// print_index_stack(a, "A should be sorted");
// 	// printf("=== END Rotate until sorted ==\n\n");
// 	// printf("Number of ops :%zu\n", ops->count);
// 	// printf("=====================================================================\n\n");
// 	// print_stack(a, "A");
// 	// print_stack(b, "B");
// 	// clear_stack(&a);
// 	// clear_stack(&b);
// 	// clear_op_list(&ops);
// 	// printf("======================================================================\n\n");
// }

void	lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	len_a;

	len_a = a->length;
	if (len_a <= 1)
		return ;
	if (len_a == 2)
	{
		sort_two(a, ops);
		return ;
	}
	if (len_a == 3)
	{
		sort_three(a, ops); // petit tri hardcode
		return ;
	}
	// add lis and index
	add_lis_to_nodes(a);
	printf("====");
	add_index_node(a);
	while (len_a > 0)
	{
		if (a->head->is_lis == 0)
			push(a, b, ops);
		else
			rotate(a, ops);
		len_a--;
	}
	insertion_sort(a, b, ops);
}

size_t	square_bucket(size_t len_stk)
{
	size_t	i;

	i = 0;
	while (i * i < len_stk)
	{
		i++;
	}
	return (i);
}
