/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:29:04 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/16 11:23:15 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_number(t_pile *a, t_pile *b)
{
	if (ft_pilesize(b) > 0)
		return (0);
	while (a->next != NULL)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	verif_pilea(t_pile *a, int bool)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
		{
			if (!a->next->next && bool)
				return (2);
			else
				return (0);
		}		
		a = a->next;
	}
	return (1);
}

int	verif_pileb(t_pile *b)
{
	while (b->next)
	{
		if (b->nbr < b->next->nbr)
			return (0);
		b = b->next;
	}
	return (1);
}
