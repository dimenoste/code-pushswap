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

// void	algo_lis(void)
// {
// 	t_stack		*a;
// 	t_stack		*b;
// 	t_op_list	*ops;
// 	size_t		max_a;
// 	int			nb_lis;

// 	// size_t		len_a;
// 	printf("============= TEST medium_algo.c: algo_lis ==================\n");
// 	ops = new_op_list();
// 	// {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
// 	// 398 → 938 → 634 → 200 → 987 → 77 → 282 → 768 → 441 → 395
// 	a = new_stack(A);
// 	stack_add_back(a, new_node(398));
// 	stack_add_back(a, new_node(938));
// 	stack_add_back(a, new_node(634));
// 	stack_add_back(a, new_node(200));
// 	stack_add_back(a, new_node(987));
// 	stack_add_back(a, new_node(77));
// 	stack_add_back(a, new_node(282));
// 	stack_add_back(a, new_node(768));
// 	stack_add_back(a, new_node(441));
// 	stack_add_back(a, new_node(395));
// 	if (a->length < 2)
// 		return ;
// 	// add lis and index
// 	nb_lis = add_lis_to_nodes(a);
// 	printf("====");
// 	assign_indices(a);
// 	// create stack b
// 	b = new_stack(B);
// 	// printf("================================== set up data before sort ====================================\n\n");
// 	// print_stack(a, "A");
// 	// print_stack(b, "B");
// 	// print_index_stack(a, "A");
// 	// print_index_stack(b, "B");
// 	// print_lis_stack(a, "A");
// 	// print_lis_stack(b, "B");
// 	printf("================================== insert non lis dans B ====================================\n\n");
// 	// push all non lis elements to B
// 	// len_a = a->length;
// 	while (nb_lis > 0)
// 	{
// 		if (a->head->is_lis == 0)
// 		{
// 			push(a, b, ops);
// 			nb_lis--;
// 		}
// 		else
// 			rotate(a, ops);
// 	}
// 	printf("========================= after insert dans B ============================================\n\n");
// 	print_stack(a, "A");
// 	print_stack(b, "B");
// 	// print_lis_stack(a, "A");
// 	// print_lis_stack(b, "B");
// 	print_index_stack(a, "A");
// 	print_index_stack(b, "B");
// 	printf("========================= reinsertion dans A ============================================\n\n");
// 	// int i = 5;
// 	while (b->length > 0) // && i > 0)
// 	{
// 		printf("head of a %d\n", a->head->value);
// 		printf("head of b %d\n", b->head->value);
// 		print_index_stack(a, "A");
// 		print_index_stack(b, "B");
// 		max_a = get_max_index(a);
// 		if (max_a < b->head->index)
// 		{
// 			push(b, a, ops);
// 			rotate(a, ops);
// 			print_index_stack(a, " max_a < b->head->index A");
// 		}
// 		else
// 		{
// 			printf("=== START Rotate until sorted ==\n\n");
// 			rotate_until_sorted(a, ops);
// 			print_index_stack(a, "A should be sorted");
// 			printf("=== END Rotate until sorted ==\n\n");
// 			while (a->head->index < b->head->index)
// 			{
// 				print_index_stack(a, " a->head->index < b->head->index A");
// 				rotate(a, ops);
// 			}
// 			if (a->head->index > b->head->index)
// 			{
// 				push(b, a, ops);
// 				print_index_stack(a, " a->head->index > b->head->index A");
// 			}
// 		}
// 		printf("=== after poush from b to a ==\n\n");
// 		print_index_stack(a, "A");
// 		print_index_stack(b, "B");
// 		// i--;
// 	} //// print and clean
// 	printf("=== START Rotate until sorted ==\n\n");
// 	rotate_until_sorted(a, ops);
// 	print_index_stack(a, "A should be sorted");
// 	printf("=== END Rotate until sorted ==\n\n");
// 	printf("Number of ops :%zu\n", ops->count);
// 	printf("=====================================================================\n\n");
// 	print_stack(a, "A");
// 	print_stack(b, "B");
// 	clear_stack(&a);
// 	clear_stack(&b);
// 	clear_op_list(&ops);
// 	printf("======================================================================\n\n");
// }

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

// static void	set_cost_directions(t_cost *c, t_stack *a, t_stack *b)
// {
// 	if (c->pos_a <= a->length / 2)
// 		c->cost_a = (int)c->pos_a;
// 	else
// 		c->cost_a = -((int)(a->length - c->pos_a));
// 	if (c->pos_b <= b->length / 2)
// 		c->cost_b = (int)c->pos_b;
// 	else
// 		c->cost_b = -((int)(b->length - c->pos_b));
// }
// // helper func pour verifier jusement si n est positif ou negatif
// static int	abs_val(int n)
// {
// 	if (n < 0)
// 		return (-n);
// 	return (n);
// }
// static int	total_cost(t_cost *c)
// {
// 	int	ca;
// 	int	cb;

// 	ca = abs_val(c->cost_a);
// 	cb = abs_val(c->cost_b);
// 	// ils sont tout les deux positif
// 	if (c->cost_a > 0 && c->cost_b > 0)
// 		return (((ca > cb) * ca) + ((ca <= cb) * cb));
// 	// ils sont tout les deux negatif meme operation booleenne
// 	if (c->cost_a < 0 && c->cost_b < 0)
// 		return (((ca > cb) * ca) + ((ca <= cb) * cb));
// 	return (ca + cb);
// }

t_cost	find_cheapest_non_lis(t_stack *a, t_stack *b)
{
	t_cost	best;
	t_cost	cur;
	t_node	*node;
	size_t	i;

	node = a->head;
	i = 0;
	best.cost_a = (int)a->length;
	best.cost_b = (int)b->length;
	while (i < a->length)
	{
		if (node->is_lis == 0)
		{
			cur.pos_a = i;
			cur.pos_b = find_insert_pos_b(b, node->index);
			set_cost_directions(&cur, a, b);
			if (total_cost(&cur) < total_cost(&best))
				best = cur;
		}
		node = node->next;
		i++;
	}
	return (best);
}
// void	lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops)
// {
// 	size_t	len_a;
// 	size_t	nb_lis;
// 	size_t	non_lis_nb;
// 	t_cost	best;
// 	size_t	best_lis_pos;

// 	// int		k;
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
// 	best_lis_pos = 0;
// 	add_index_node(a);
// 	best_lis_pos = find_best_lis(a);
// 	rotate_to_top(a, best_lis_pos, ops);
// 	nb_lis = add_lis_to_nodes(a, &best_lis_pos);
// 	non_lis_nb = (a->length - nb_lis);
// 	printf("==number of lis elemetns %ld==\n", nb_lis);
// 	// print_stack(a, "A stack");
// 	// print_index_stack(a, "A index after lis");
// 	// print_lis_stack(a, "LIS ELEM IN A", nb_lis);
// 	printf("=====================================================================\n\n");
// 	b->length = 0;
// 	// k = 40;
// 	while (b->length < non_lis_nb)
// 	{
// 		// printf("len of B %ld\n", b->length);
// 		if (a->head->is_lis == 0)
// 		{
// 			// push(a, b, ops);
// 			// best = find_cheapest_non_lis(a, b);
// 			// // print_stack(a, "A");
// 			execute_rotations(a, b, ops, &best);
// 			push(a, b, ops);
// 		}
// 		else
// 			rotate(a, ops);
// 		// k--;
// 		// if (k == 0)
// 		// {
// 		// 	printf("infinite loop\n");
// 		// 	return ;
// 		// }
// 	}
// 	// print_stack(a, "A after lis");
// 	// print_index_stack(a, "A index after lis");
// 	// print_lis_stack(a, "LIS ELEM IN A", nb_lis);
// 	// print_stack(b, "B after lis");
// 	// print_index_stack(b, "B index after lis");
// 	// print_lis_stack(b, "LIS ELEM IN B", nb_lis);
// 	printf("=====================================================================\n\n");
// 	// insertion_sort(a, b, ops);
// 	// execute_rotations(a, b, ops, &best);
// 	push_all_to_a(a, b, ops);
// 	printf("Number of ops :%zu\n", ops->count);
// 	// printf("=====================================================================\n\n");
// 	// print_stack(a, "A");
// 	// print_stack(b, "B");
// }

static size_t	eval_rot(int *arr, int n, int start)
{
	int		*tmp;
	size_t	len;
	size_t	pos;
	int		i;

	tmp = malloc(sizeof(int) * n);
	if (!tmp)
		return (0);
	i = 0;
	while (i < n)
	{
		tmp[i] = arr[(start + i) % n];
		i++;
	}
	free(get_lis(tmp, n, &len, &pos));
	free(tmp);
	return (len);
}

size_t	find_best_lis(t_stack *stk)
{
	int		*arr;
	size_t	best_len;
	size_t	best_pos;
	size_t	i;
	size_t	cur;

	if (!stk || stk->length < 2 || !stk->head)
		return (0);
	arr = copy_values(stk);
	if (!arr)
		return (0);
	best_len = 0;
	best_pos = 0;
	i = 0;
	while (i < stk->length)
	{
		cur = eval_rot(arr, stk->length, i);
		if (cur > best_len)
		{
			best_len = cur;
			best_pos = i;
		}
		i++;
	}
	free(arr);
	return (best_pos);
}

static int	handle_small_cases(t_stack *a, t_op_list *ops)
{
	if (a->length <= 1)
		return (1);
	if (a->length == 2)
	{
		sort_two(a, ops);
		return (1);
	}
	if (a->length == 3)
	{
		sort_three(a, ops);
		return (1);
	}
	return (0);
}

static size_t	prepare_lis(t_stack *a, t_op_list *ops)
{
	size_t	best_pos;
	size_t	nb_lis;

	best_pos = find_best_lis(a);
	rotate_to_top(a, best_pos, ops);
	nb_lis = add_lis_to_nodes(a, &best_pos);
	return (nb_lis);
}

static void	push_non_lis(t_stack *a, t_stack *b, t_op_list *ops, size_t nb_lis)
{
	size_t	target;
	t_cost	best;

	target = a->length - nb_lis;
	while (b->length < target)
	{
		if (!a->head->is_lis)
		{
			best = find_cheapest_non_lis(a, b);
			execute_rotations(a, b, ops, &best);
			push(a, b, ops);
		}
		else
			rotate(a, ops);
	}
}

void	lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	nb_lis;

	if (handle_small_cases(a, ops))
		return ;
	add_index_node(a);
	nb_lis = prepare_lis(a, ops);
	printf("non lis found %zu\n", nb_lis);
	push_non_lis(a, b, ops, nb_lis);
	push_all_to_a(a, b, ops);
}
