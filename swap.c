/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:34:48 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 09:44:36 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile *a, int bool)
{
	int		tmp;
	int		arraytmp;

	tmp = a->next->nbr;
	arraytmp = a->next->array;
	a->next->nbr = a->nbr;
	a->next->array = a->array;
	a->nbr = tmp;
	a->array = arraytmp;
	if (bool)
		write(1, "sa\n", 3);
}

void	sb(t_pile *b, int bool)
{
	int		tmp;
	int		arraytmp;

	tmp = b->next->nbr;
	arraytmp = b->next->array;
	b->next->nbr = b->nbr;
	b->next->array = b->array;
	b->nbr = tmp;
	b->array = arraytmp;
	if (bool)
		write(1, "sb\n", 3);
}

void	ss(t_pile *a, t_pile *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
