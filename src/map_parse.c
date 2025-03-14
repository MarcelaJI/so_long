/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:55:39 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 11:07:56 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map_name(int argc, char *path)
{
	int	l;

	if (argc == 1)
		return (print_error("no name provided"), 0);
	if (argc > 2)
		return (print_error("too many arguments"), 0);
	l = ft_strlen(path) - 1;
	if (path[l - 3] != '.'
		|| path[l - 2] != 'b'
		|| path[l - 1] != 'e'
		|| path[l] != 'r')
		return (print_error("invalid map name"), 0);
	return (1);
}

static int	map_height(char *map_path)
{
	int		height;
	char	*line;
	int		map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (print_error("map file does not exist"), 0);
	height = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	return (height);
}

static void	loadMapData(char ***arr, char *map_path)
{
	int		map_fd;
	int		i;
	char	*line;

	map_fd = open(map_path, O_RDONLY);
	i = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		(*arr)[i] = ft_strtrim(line, "\n\r");
		if ((*arr)[i] == NULL)
			freeGameArrOnError(arr, i);
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	free(line);
	close(map_fd);
}

static char	**get_map_arr(char *map_path)
{
	char	**arr;
	int		height;

	height = map_height(map_path);
	if (height == 0)
		return (print_error("empty file"), NULL);
	arr = malloc(sizeof(char *) * (height + 1));
	if (!arr)
		return (NULL);
	arr[height] = NULL;
	loadMapData(&arr, map_path);
	return (arr);
}

int	load_map(char *map_path, t_game *game)
{
	game->map_arr = get_map_arr(map_path);
	if (!(game->map_arr))
		return (0);
	if (!is_map_rectangular(game))
		return (0);
	if (!is_map_walls(game))
		return (0);
	if (!validate_map_chars(game->map_arr))
		return (0);
	if (!validate_game_elements(game))
		return (0);
	findElementPosition(game, 'P', &(game->d->pos));
	findElementPosition(game, 'E', &(game->e_pos));
	if (!check_element_accessibility(game))
		return (0);
	game->width = game->cols * TILE_SIZE;
	game->height = game->rows * TILE_SIZE;
	game->mlx = mlx_init(game->width, game->height, "Dragon Escape", true);
	if (!game->mlx)
		return (print_error("Failed to mount MLX library"), 0);
	if (!load_game_images(game))
		return (0);
	game->d->current_state = game->d->dragon_right;
	return (1);
}
