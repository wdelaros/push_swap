/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:04:07 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/20 10:05:26 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_number(t_pile *pile)
{
	int	num;

	num = pile->nbr;
	while (pile != NULL)
	{
		if (pile->nbr < num)
			num = pile->nbr;
		pile = pile->next;
	}
	return (num);
}

int	max_number(t_pile *pile)
{
	int	num;

	num = pile->nbr;
	while (pile != NULL)
	{
		if (pile->nbr > num)
			num = pile->nbr;
		pile = pile->next;
	}
	return (num);
}

int	min_index(t_pile *pile)
{
	t_pile	*tmp;
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = pile;
	num = tmp->nbr;
	while (tmp != NULL)
	{
		if (tmp->nbr < num)
		{
			num = tmp->nbr;
			j = i;
		}
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	if (j <= ft_pilesize(pile) / 2 || j == 1)
		return (1);
	else
		return (0);
}

int	max_index(t_pile *pile)
{
	t_pile	*tmp;
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = pile;
	num = tmp->nbr;
	while (tmp != NULL)
	{
		if (tmp->nbr > num)
		{
			num = tmp->nbr;
			j = i;
		}
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	if (j <= ft_pilesize(pile) / 2)
		return (1);
	else
		return (0);
}
