/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:29:36 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/27 21:00:01 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_list	*new_op_list(void)
{
	t_op_list	*list;

	list = malloc(sizeof(t_op_list));
	if (!list)
		return (NULL);
	list->operations = NULL;
	list->count = 0;
	list->capacity = 0;
	return (list);
}

void	add_operation(t_op_list *list, t_op_type op)
{
	t_op_type	*new_ops;
	size_t		i;

	if (list->count >= list->capacity)
	{
		if (list->capacity == 0)
			list->capacity = 1024;
		else
			list->capacity = list->capacity * 2;
		new_ops = malloc(sizeof(t_op_type) * list->capacity);
		if (!new_ops)
			return ;
		i = 0;
		while (i < list->count)
		{
			new_ops[i] = list->operations[i];
			i++;
		}
		free(list->operations);
		list->operations = new_ops;
	}
	list->operations[list->count] = op;
	list->count++;
}

void	print_operations(t_op_list *list)
{
	size_t		i;
	const char	*names[11] = {"sa\n", "sb\n", "ss\n", "pa\n",
		"pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	size_t		len;

	i = 0;
	while (i < list->count)
	{
		if (list->operations[i] >= OP_RRA)
			len = 4;
		else
			len = 3;
		write(1, names[list->operations[i]], len);
		i++;
	}
}

void	clear_op_list(t_op_list **list)
{
	if (!list || !(*list))
		return ;
	if ((*list)->operations)
		free((*list)->operations);
	free(*list);
	*list = NULL;
}
