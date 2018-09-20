/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndziman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 08:47:09 by tndziman          #+#    #+#             */
/*   Updated: 2018/06/14 15:32:49 by tndziman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_isneg(int *n, int *nega)
{
	if (*n < 0)
	{
		*n *= -1;
		*nega = 1;
	}
}

char	*ft_itoa(int n)
{
	int	tmp_num;
	int	len;
	int	neg;
	char *str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp_num = n;
	len = 2;
	neg = 0;
	ft_isneg(&n, &neg);
	while (tmp_num /= 10)
	   len++;
	len += neg;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
