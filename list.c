/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:21:01 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/16 07:40:01 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*create_node(int num)
{
	t_pile	*node;

	node = (t_pile *)malloc(sizeof(t_pile));
	if (!node)
		return (0);
	node->nbr = num;
	node->array = 0;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

int	ft_pilesize(t_pile *pile)
{
	if (!pile)
		return (0);
	return (ft_pilesize(pile->next) + 1);
}
