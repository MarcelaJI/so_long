/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:11:49 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/31 09:12:01 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	import_image(t_game *game, mlx_image_t **img, char *img_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(img_path);
	if (!texture)
		return (print_error("image not found"), 0);
	*img = mlx_texture_to_image(game->mlx, texture);
	if (!(*img))
		return (print_error("error while mounting image"), 0);
	mlx_delete_texture(texture);
	return (1);
}

void	render_image(t_game *game, mlx_image_t *img, int32_t x, int32_t y)
{
	mlx_resize_image(img, TILE_SIZE, TILE_SIZE);
	mlx_image_to_window(game->mlx, img, x, y);
}
