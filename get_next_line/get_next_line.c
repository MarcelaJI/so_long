/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:15:40 by ingjimen          #+#    #+#             */
/*   Updated: 2024/10/28 12:34:46 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1u];
	char		*holder;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = NULL;
	bytes = 0;
	while (!holder || !gnl_strchr(holder, '\n'))
	{
		if (!*buff)
		{
			bytes = read(fd, buff, BUFFER_SIZE);
			if (bytes == 0)
				return (holder);
			if (bytes < 0 && holder)
				free(holder);
			if (bytes < 0)
				return (NULL);
			buff[bytes] = '\0';
		}
		holder = appendbuff(holder, buff);
	}
	return (holder);
}
