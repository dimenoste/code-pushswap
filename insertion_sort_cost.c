/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:59:23 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/03/05 21:46:29 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ca calcule le "cout" d'une operation sur notre rond
// en gros on choisis le chemin le plus court si l'element
// y'a deux chemins possible si on divise notre rond par deux
// pour ca je me suis appuyee sur si P+ = {0,...INT MAX}
// donc cout dans les positif (le rang d'une valeur positive est forcement
// plus simple a tourner avec un simple ra)
// Les éléments du groupe "proche du haut" → coût faible
// sinon on tourne vers le "bas" = P- = {INT MIN,...0}
// donc c'est plus court par l'autre cote si on a divise par 2 la taille
// Les éléments du groupe "proche du bas" → coût élevé (mais négatif = court)
// donc rra;
void	set_cost_directions(t_cost *c, t_stack *a, t_stack *b)
{
	if (c->pos_a <= a->length / 2)
		c->cost_a = (int)c->pos_a;
	else
		c->cost_a = -((int)(a->length - c->pos_a));
	if (c->pos_b <= b->length / 2)
		c->cost_b = (int)c->pos_b;
	else
		c->cost_b = -((int)(b->length - c->pos_b));
}
// helper func pour verifier jusement si n est positif ou negatif
int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
 si les deux négatifs (rotate backward) → on va utiliser rrr
**   même logique, coût = max(ca, cb)
**
** pro tips  booléen pour trouver le max (merci la fac d'info) :
**   (ca > cb) vaut 1 si vrai, 0 si faux
**   donc si ca > cb : on garde ca (multiplié par 1), cb devient 0
**   si ca <= cb : on garde cb (multiplié par 1), ca devient 0
**   une seule valeur survit → c'est le maximum ! ^^
*/
int	total_cost(t_cost *c)
{
	int	ca;
	int	cb;

	ca = abs_val(c->cost_a);
	cb = abs_val(c->cost_b);
	if (c->cost_a > 0 && c->cost_b > 0)
		return ((ca > cb) * ca + (ca <= cb) * cb);
	if (c->cost_a < 0 && c->cost_b < 0)
		return ((ca > cb) * ca + (ca <= cb) * cb);
	return (ca + cb);
}

t_cost	find_cheapest(t_stack *a, t_stack *b)
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
		cur.pos_a = i;
		cur.pos_b = find_insert_pos_b(b, node->index);
		set_cost_directions(&cur, a, b);
		if (total_cost(&cur) < total_cost(&best))
			best = cur;
		node = node->next;
		i++;
	}
	return (best);
}

void	execute_rotations(t_stack *a, t_stack *b, t_op_list *ops, t_cost *c)
{
	while (c->cost_a > 0 && c->cost_b > 0)
	{
		rotate_both(a, b, ops);
		c->cost_a--;
		c->cost_b--;
	}
	while (c->cost_a < 0 && c->cost_b < 0)
	{
		reverse_rotate_both(a, b, ops);
		c->cost_a++;
		c->cost_b++;
	}
	while (c->cost_a > 0 && c->cost_a--)
		rotate(a, ops);
	while (c->cost_a < 0 && c->cost_a++)
		reverse_rotate(a, ops);
	while (c->cost_b > 0 && c->cost_b--)
		rotate(b, ops);
	while (c->cost_b < 0 && c->cost_b++)
		reverse_rotate(b, ops);
}
