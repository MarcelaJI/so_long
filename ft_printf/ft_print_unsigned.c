/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:33:27 by ingjimen          #+#    #+#             */
/*   Updated: 2024/11/07 08:55:34 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}
