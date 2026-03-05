#include "push_swap.h"


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
	stk->head = head_orig;
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
		return ;
	}
	ptr_min = stk->head;
	pos_min = find_min_ptr_pos(stk, &ptr_min);
	if (pos_min == 0)
	{
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
		nb_rotate--;
	}
	return ;
}


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
