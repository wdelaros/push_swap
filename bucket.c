/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:50:23 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/16 10:53:01 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index_bucket(t_pile *a, int nbr, int nbrmax)
{
	t_pile	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->nbr == nbrmax)
			k = i;
		if (tmp->nbr == nbr)
			j = i;
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	k = i - k;
	if (j <= k + 1 || j == 1)
		return (1);
	else
		return (0);
}

double	min_bucket(t_pile *a, int bucket)
{
	t_pile	*tmp;

	tmp = a;
	while (a != NULL)
	{
		if (a->array == bucket && a->nbr != max_number(tmp))
			return (a->nbr);
		a = a->next;
	}
	return (1.5);
}

double	max_bucket(t_pile *a, int bucket)
{
	t_pile	*tmp;

	tmp = a;
	while (a->next != NULL)
		a = a->next;
	while (a != NULL)
	{
		if (a->array == bucket && a->nbr != max_number(tmp))
			return (a->nbr);
		a = a->previous;
	}
	return (1.5);
}

int	number_bucket(t_pile *a, int nbr, int array)
{
	t_pile	*pile;
	int		num;

	num = max_number(a);
	pile = a;
	while (pile != NULL)
	{
		if (pile->nbr <= num && pile->nbr > nbr)
			num = pile->nbr;
		if (pile->nbr == min_number(a) && pile->array != 1)
			pile->array = 1;
		pile = pile->next;
	}
	while (a->nbr != num)
		a = a->next;
	a->array = array;
	nbr = num;
	free(pile);
	return (nbr);
}

void	bucket(t_pile **a, int bnbr, int i)
{
	int	bucket_size;
	int	nbr;
	int	j;

	if (ft_pilesize(*a) >= 500)
		bnbr = 13;
	else if (ft_pilesize(*a) >= 100)
		bnbr = 6;
	bucket_size = ft_pilesize(*a) / bnbr;
	nbr = min_number(*a);
	j = 1;
	while (++i != bnbr + 1)
	{
		if (i == bnbr)
		{
			j = bucket_size + (ft_pilesize(*a) - (bucket_size * i));
			while (j-- > 0)
				nbr = number_bucket(*a, nbr, i);
		}
		else
			while (j++ != bucket_size)
				nbr = number_bucket(*a, nbr, i);
		j = 0;
	}
}
