/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:31:57 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 11:13:52 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	floodfill(t_game *game, int p_x, int p_y)
{
	char	**map_arr;

	map_arr = game->map_arr;
	if (p_y < 0 || p_y >= game->rows
		|| p_x < 0 || p_x >= game->cols
		|| map_arr[p_y][p_x] == '1'
		|| game->flood_visited[p_y][p_x])
		return ;
	if (map_arr[p_y][p_x] == 'E')
		game->flood_e_count++;
	if (map_arr[p_y][p_x] == 'C')
		game->flood_c_count++;
	game->flood_visited[p_y][p_x] = 1;
	floodfill(game, p_x, p_y - 1);
	floodfill(game, p_x, p_y + 1);
	floodfill(game, p_x - 1, p_y);
	floodfill(game, p_x + 1, p_y);
}

void	find_element_position(t_game *game, char c, t_pos **pos)
{
	int		y;
	int		x;
	char	**map_arr;

	y = 0;
	map_arr = game->map_arr;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (map_arr[y][x] == c)
			{
				(*pos)->x = x;
				(*pos)->y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

static void	get_visited_arr(t_game *game)
{
	char	**map_arr;
	char	**visited;
	int		y;
	int		row_len;

	map_arr = game->map_arr;
	visited = malloc(sizeof(char *) * (game->rows + 1));
	if (!visited)
		return ;
	y = 0;
	while (y < game->rows)
	{
		row_len = ft_strlen(map_arr[y]);
		visited[y] = ft_calloc(row_len, sizeof(char));
		if (!visited[y])
		{
			free_game_on_error(&visited, y);
			return ;
		}
		y++;
	}
	visited[game->rows] = NULL;
	game->flood_visited = visited;
}

int	check_element_accessibility(t_game *game)
{
	get_visited_arr(game);
	if (!game->flood_visited)
		return (0);
	floodfill(game, game->d->pos->x, game->d->pos->y);
	release_map_array(&(game->flood_visited));
	if (game->flood_c_count != game->c_count)
		return (print_error("collectables not reachable"), 0);
	if (game->flood_e_count != 1)
		return (print_error("exit not reachable"), 0);
	return (1);
}
