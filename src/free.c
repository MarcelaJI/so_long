/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:28:22 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 11:11:33 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*release_map_array(char ***map_arr)
{
	char	**arr;
	int		i;

	arr = *map_arr;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	return (NULL);
}

void	free_game(t_game **game)
{
	if ((*game)->map_arr)
		release_map_array(&((*game)->map_arr));
	if ((*game)->d->pos)
		free((*game)->d->pos);
	if ((*game)->d)
		free((*game)->d);
	if ((*game)->assets)
		free((*game)->assets);
	if ((*game)->e_pos)
		free((*game)->e_pos);
	free(*game);
	*game = NULL;
}

void	*free_game_on_error(char ***arr, size_t iterator)
{
	while (iterator > 0)
		free((*arr)[--iterator]);
	free(*arr);
	return (NULL);
}

void	free_mlx(t_game *game)
{
	mlx_delete_image(game->mlx, game->assets->coll);
	mlx_delete_image(game->mlx, game->assets->e_curr_state);
	mlx_delete_image(game->mlx, game->assets->exit_closed);
	mlx_delete_image(game->mlx, game->assets->exit_open);
	mlx_delete_image(game->mlx, game->assets->floor);
	mlx_delete_image(game->mlx, game->assets->obst_1);
	mlx_delete_image(game->mlx, game->assets->obst_2);
	mlx_delete_image(game->mlx, game->assets->obst_3);
	mlx_delete_image(game->mlx, game->assets->wall_hor);
	mlx_delete_image(game->mlx, game->assets->wall_lower_l);
	mlx_delete_image(game->mlx, game->assets->wall_lower_r);
	mlx_delete_image(game->mlx, game->assets->wall_upper_l);
	mlx_delete_image(game->mlx, game->assets->wall_upper_r);
	mlx_delete_image(game->mlx, game->assets->wall_ver_l);
	mlx_delete_image(game->mlx, game->assets->wall_ver_r);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
}
