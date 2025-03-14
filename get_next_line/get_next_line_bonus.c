/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:20:22 by ingjimen          #+#    #+#             */
/*   Updated: 2024/10/28 11:41:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[10240][BUFFER_SIZE + 1u];
	char		*holder;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = NULL;
	bytes = 0;
	while (!holder || !gnl_strchr(holder, '\n'))
	{
		if (!*buff[fd])
		{
			bytes = read(fd, buff[fd], BUFFER_SIZE);
			if (bytes == 0)
				return (holder);
			if (bytes < 0 && holder)
				free(holder);
			if (bytes < 0)
				return (NULL);
			buff[fd][bytes] = '\0';
		}
		holder = appendbuff(holder, buff[fd]);
	}
	return (holder);
}
