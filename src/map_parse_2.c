/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:15:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 09:30:45 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_rectangular(t_game *game)
{
	int		x;
	int		y;
	int		current_len;
	char	**map_arr;

	current_len = 0;
	map_arr = game->map_arr;
	while (map_arr[0][current_len])
		current_len++;
	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
			x++;
		if (x != current_len)
			return (print_error("map is not rectangular"), 0);
		current_len = x;
		y++;
	}
	game->cols = current_len;
	game->rows = y;
	return (1);
}

int	is_map_walls(t_game *game)
{
	int		y;
	int		x;
	char	**map_arr;

	y = game->rows;
	map_arr = game->map_arr;
	x = 0;
	while (map_arr[y - 1][x])
	{
		if (map_arr[y - 1][x] != '1' || map_arr[0][x] != '1')
			return (print_error("map not enclosed by walls"), 0);
		x++;
	}
	y -= 2;
	while (y > 0)
	{
		x = ft_strlen(map_arr[y]);
		if (map_arr[y][0] != '1' || map_arr[y][x - 1] != '1')
			return (print_error("map not enclosed by walls"), 0);
		y--;
	}
	return (1);
}

int	validate_map_chars(char **map_arr)
{
	int	x;
	int	y;

	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (!ft_check_char(map_arr[y][x], "10PEC"))
				return (print_error("invalid character in map"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	count_element(char **map_arr, char c)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (map_arr[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	validate_game_elements(t_game *game)
{
	int		c;
	int		e;
	int		p;
	int		obstac;
	char	**map_arr;

	map_arr = game->map_arr;
	c = count_element(map_arr, 'C');
	e = count_element(map_arr, 'E');
	p = count_element(map_arr, 'P');
	if (c < 1)
		return (print_error("not enough collectables"), 0);
	if (e != 1)
		return (print_error("invalid exit"), 0);
	if (p != 1)
		return (print_error("invalid initial position"), 0);
	game->c_count = c;
	obstac = count_element(map_arr, '1');
	obstac = obstac - (((game->cols) * 2) + (((game->rows) - 2) * 2));
	game->obstac_count = obstac;
	return (1);
}
