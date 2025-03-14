/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:35:54 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 10:38:50 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argc, char *args[])
{
	t_game	*game;

	if (!validate_map_name(argc, args[1]))
		return (1);
	game_init(&game);
	if (!game
		|| !(game->d)
		|| !(game->d->pos)
		|| !(game->assets)
		|| !(game->e_pos))
		return (free_game(&game), 1);
	if (!load_map(args[1], game))
		return (free_game(&game), 1);
	begin_game(game);
	return (EXIT_SUCCESS);
}
