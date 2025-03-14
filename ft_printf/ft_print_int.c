/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:18 by ingjimen          #+#    #+#             */
/*   Updated: 2024/11/07 09:32:07 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int		i;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	i = 0;
	if (n < 0)
	{
		i += ft_print_char('-');
		n *= -1;
	}
	if (n > 9)
		i += ft_print_int(n / 10);
	i += ft_print_char((n % 10) + '0');
	return (i);
}
