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
	stk->head = head_orig; // reset the head at the original node
	return (is_sorted);
}
void	rotate_until_sorted(t_stack *stk, t_op_list *ops)
{
	size_t		pos_min;
	t_node		*ptr_min;
	rotate_f	rot;

	if (!stk || !stk->head || stk->length < 2 || !is_sorted_circular(stk))
		return ;
	ptr_min = stk->head;
	pos_min = find_min_ptr_pos(stk, &ptr_min);
	if (ptr_min->index != 0 || pos_min == 0)
	// pos min should be from 1 to len of stack
	{
		printf("error, ptr should point to node with 0 index and min value\n");
		printf("index found for the min is %zu\n", ptr_min->index);
		return ;
	}
	if (pos_min < stk->length / 2)
		rot = &rotate;
	else
		rot = &reverse_rotate;
	while (pos_min > 1)
	{
		rot(stk, ops);
		pos_min--;
	}
	return ;
}
void	algo_lis(void)
{
	t_stack		*a;
	t_stack		*b;
	t_op_list	*ops;
	size_t		len_a;

	printf("============= TEST medium_algo.c: algo_lis ==================\n");
	ops = new_op_list();
	// {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
	a = new_stack(A);
	stack_add_back(a, new_node(8));
	stack_add_back(a, new_node(3));
	stack_add_back(a, new_node(4));
	stack_add_back(a, new_node(6));
	stack_add_back(a, new_node(5));
	stack_add_back(a, new_node(2));
	stack_add_back(a, new_node(0));
	stack_add_back(a, new_node(7));
	stack_add_back(a, new_node(9));
	stack_add_back(a, new_node(1));
	if (a->length < 2)
		return ;
	// add lis and index
	add_lis_to_nodes(a);
	printf("====");
	assign_indices(a);
	// create stack b
	b = new_stack(B);
	printf("================================== insert non lis dans B ====================================\n\n");
	// push all non lis elements to B
	len_a = a->length;
	while (len_a > 0)
	{
		if (a->head->is_lis == 0)
			push(a, b, ops);
		else
			rotate(a, ops);
		print_stack(a, "A");
		print_stack(b, "B");
		len_a--;
	}
	print_stack(a, "A");
	print_stack(b, "B");
	print_lis_stack(a, "A");
	print_lis_stack(b, "B");
	printf("========================= reinsertion dans A ============================================\n\n");
	// int i = 5;
	while (b->length > 0) // && i > 0)
	{
		printf("head of a %d\n", a->head->value);
		printf("head of b %d\n", b->head->value);
		print_stack(a, "A");
		print_stack(b, "B");
		if (a->head->index > b->head->index)
			push(b, a, ops);
		else
			rotate(a, ops);
		// i--;
	}
	printf("=== A should be circularly up to now rotated,rotate until start with 0 ==\n\n");
	rotate_until_sorted(a, ops);
	//// print and clean
	printf("=====================================================================\n\n");
	print_stack(a, "A");
	print_stack(b, "B");
	clear_stack(&a);
	clear_stack(&b);
	clear_op_list(&ops);
	printf("======================================================================\n\n");
}

void	lis_insertion_algo(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	len_a;

	if (a->length < 2)
		return ;
	// add lis and index
	add_lis_to_nodes(a);
	assign_indices(a);
	// push all non lis elements to B
	len_a = a->length;
	while (len_a > 0)
	{
				printf("head of a %d\n", a->head->value);
		printf("head of b %d\n", b->head->value);
		print_stack(a, "A");
		print_stack(b, "B");
		if (a->head->is_lis == 0)
			push(a, b, ops);
		else
			rotate(a, ops);
		len_a--;
	}
	print_stack(a, "A");
	print_stack(b, "B");
	print_index_stack(a, "A");
	print_index_stack(b, "B");
	print_lis_stack(a, "A");
	print_lis_stack(b, "B");
	// int i = 5;
	while (b->length > 0) // && i > 0)
	{
		if (a->head->index > b->head->index)
		{
			push(b, a, ops);
		}
		else
			rotate(a, ops);
		// i--;
	}
	printf("=== A should be circularly up to now rotated,rotate until start with 0 ==\n\n");
	rotate_until_sorted(a, ops);
	//// print and clean
	printf("=====================================================================\n\n");
	print_stack(a, "A");
	print_stack(b, "B");
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
