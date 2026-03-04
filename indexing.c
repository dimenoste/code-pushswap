/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:20:11 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/03 14:47:48 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * C'est comme le Bubble sort que tu voulais faire pour
 * trier,
 * arr[0] = le plus petit, arr[len -1] = plus grand
 * bref chaque position "triee" = le rang de cette valeur
 *
 * */

static void	sort_long_array(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i]) // si on trouve plus petit on echange
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// trouver le fameux rang dans l'array trie
static size_t	find_index(int *sorted, size_t len, int value)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1); // on a pas trouver value dans l'array (ca devrait pas arriver)
}

/*
 * copie les valeurs de la stack dans un tableau
 * c'est une implementation de flemmard pcq c'est
 * plus facile de trier un tableau qu'une liste
 * */

int	*copy_values(t_stack *stk)
{
	int		*arr;
	t_node	*cur;
	size_t	i;

	arr = malloc(sizeof(long) * stk->length);
	if (!arr)
		return (NULL);
	cur = stk->head;
	i = 0;
	while (i < stk->length)
	{
		arr[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (arr);
}
/*
 * C'est la normalisation dont on parlait
 * je le faisais de maniere degueu dans find
 * insert pos b.
 * tu sais genre : [500, -3, 42] → rang [2, 0, 1]
 * ca copie dans un tab; trie chaque pos a un rang
 *[our chaque noeud, cherche le rang de sa valeur
 * */

void	assign_indices(t_stack *stk)
{
	int		*sorted;
	t_node	*cur;
	size_t	i;

	if (!stk || stk->length == 0)
		return ;
	sorted = copy_values(stk);
	if (!sorted)
		return ;
	// vu que y'a un malloc dans copy_values
	sort_long_array(sorted, stk->length); //;) conversion de type
	cur = stk->head;
	i = 0;
	while (i < stk->length)
	{
		// chaque noeud recoit son rang ^0^
		cur->index = find_index(sorted, stk->length, cur->value);
		cur = cur->next;
		i++;
	}
	free(sorted);
}
