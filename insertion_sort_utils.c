/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:09:09 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/06 16:40:57 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_max_pos(t_stack *stk)
{
	t_node	*current;
	size_t	max_idx;
	size_t	max_pos;
	size_t	i;

	current = stk->head;
	max_idx = current->index;
	max_pos = 0;
	i = 1;
	while (i < stk->length)
	{
		current = current->next;
		if (current->index > max_idx)
		{
			max_idx = current->index;
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

/*
** find_insert_pos_b
**
** idee simple : b doit TOUJOURS rester en ordre decroissant (mais en cercle
du coup t'as vu)
** donc on ne push jamais au hasard dedans.
**
** cette fonction dit juste :
** "si je veux envoyer index dans b, a quelle position il doit arriver
**  pour que l'ordre reste bon ?"
**
** on prend le max comme point d'ancrage logique (regarde find_max_pos)
** parce que dans un cercle decroissant :
** max ... min ... max (ça boucle)
**
** cas 1 : index > max  → nouveau max → on le met a la position du max
** cas 2 : index < min  → nouveau min → meme endroit logique (min touche max)
** cas 3 : sinon on cherche le trou ou :
**         (cur->index > index) > (cur->next->index)
**
** le % length sert juste a rester dans le cercle (reboucler a 0)
**
** IMPORTANT :
** contrairement a ce que je croyais cette fonction ne fait rien toute seule.
** maintenant elle est utilisee par find_cheapest(),
** qui est lui meme appele par push_cheapest_to_b().
**
** donc le flow c'est :
**   push_cheapest_to_b
**       → find_cheapest
**           → find_insert_pos_b
**
** on calcule la bonne position dans b,
** ensuite on rotate b jusqu'a cette position,
** PUIS on fait pb.
**
** c'est ça qui garantit que b reste toujours decroissante.
**
** si tu comprends pas regarde direct :
**   - find_cheapest
**   - execute_rotations
**   - push_cheapest_to_b
*/
size_t	find_insert_pos_b(t_stack *b, size_t index)
{
	t_node	*cur;
	size_t	pos;
	size_t	max_pos;

	if (b->length == 0)
		return (0);
	max_pos = find_max_pos(b);
	if (index > get_node_at(b, max_pos)->index)
		return (max_pos);
	pos = (max_pos + b->length - 1) % b->length;
	if (index < get_node_at(b, pos)->index)
		return (max_pos);
	cur = b->head;
	pos = 0;
	while (pos < b->length)
	{
		if (cur->index > index && cur->next->index < index)
			return ((pos + 1) % b->length);
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

// pareil
static size_t	find_insert_pos_a(t_stack *a, size_t index)
{
	t_node	*cur;
	size_t	pos;
	size_t	min_pos;

	min_pos = find_min_pos(a);
	if (index < get_node_at(a, min_pos)->index)
		return (min_pos);
	pos = (min_pos + a->length - 1) % a->length;
	if (index > get_node_at(a, pos)->index)
		return (min_pos);
	cur = a->head;
	pos = 0;
	while (pos < a->length)
	{
		if (cur->index < index && cur->next->index > index)
			return ((pos + 1) % a->length);
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

void	push_all_to_a(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	target;

	while (b->length > 0)
	{
		target = find_insert_pos_a(a, b->head->index);
		rotate_to_top(a, target, ops);
		push(b, a, ops);
	}
	target = find_min_pos(a);
	rotate_to_top(a, target, ops);
}
