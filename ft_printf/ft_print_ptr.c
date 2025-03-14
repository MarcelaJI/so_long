/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:44 by ingjimen          #+#    #+#             */
/*   Updated: 2024/11/13 11:20:26 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	long	n;
	int		count;

	count = 0;
	if (ptr == NULL)
	{
		count += write (1, "(nil)", 5);
		return (count);
	}
	n = (unsigned long)ptr;
	count += ft_print_str("0x");
	count += ft_print_hex(n, 0);
	return (count);
}
