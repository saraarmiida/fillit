/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:57:02 by spentti           #+#    #+#             */
/*   Updated: 2019/10/23 21:12:16 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int min;

	min = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			ft_putstr("2147483648");
		else
			n = n * -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	if (n != -2147483648)
		ft_putchar(n % 10 + 48);
}