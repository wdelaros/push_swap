/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:01:53 by wdelaros          #+#    #+#             */
/*   Updated: 2023/03/28 07:52:06 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_min_max(long int num, int neg)
{
	if ((num > MINT && neg == 1) || (num - 1 > MINT && neg == -1))
		return (0);
	return (1);
}

double	ft_atoi(const char *str)
{
	long int	num;
	int			neg;

	num = 0;
	neg = 1;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		neg *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num *= 10;
		num += *str - 48;
		str++;
		if (!check_min_max(num, neg) || *str == 43 || *str == 45)
			return (1.5);
	}
	return (num * neg);
}
