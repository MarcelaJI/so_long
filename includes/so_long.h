/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 07:59:09 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 11:16:05 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <MLX42/MLX42.h>
# include "MLX42/MLX42.h"
# include <math.h>

// Colors

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

# define TILE_SIZE 64

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_dragon
{
    struct s_pos    *pos;
    mlx_image_t     *dragon_right;
    mlx_image_t     *dragon_left;
    mlx_image_t     *current_state;
    uint32_t        collect_count;
}   t_dragon;

typedef struct s_game_assets
{
    mlx_image_t	*coll;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
	mlx_image_t	*e_curr_state;
	mlx_image_t	*obst_1;
	mlx_image_t	*obst_2;
	mlx_image_t	*obst_3;
	mlx_image_t	*floor;
	mlx_image_t	*wall_hor;
	mlx_image_t	*wall_ver_l;
	mlx_image_t	*wall_ver_r;
	mlx_image_t	*wall_lower_l;
	mlx_image_t	*wall_lower_r;
	mlx_image_t	*wall_upper_l;
	mlx_image_t	*wall_upper_r;
}   t_game_assets;

typedef struct s_game
{
	char					**map_arr;
	char					**flood_visited;
	int						flood_e_count;
	int						flood_c_count;
	struct s_dragon			*d;
	int						c_count;
	int						obstac_count;
	struct s_pos			*e_pos;
	int						rows;
	int						cols;
	uint32_t				width;
	uint32_t				height;
	mlx_t					*mlx;
	struct s_game_assets	*assets;
}	t_game;

void    print_error(char *msg);

// Map parsing
int    validate_map_name(int argc, char *path); //check_map_name
int     load_map(char *map_path, t_game *game); //parse_map
int     is_map_rectangular(t_game *game); // check_map_rectang
int     is_map_walls(t_game *game); // 
int     validate_map_chars(char **map_arr); // check_invalid_char
int     validate_game_elements(t_game *game); // check_elements
int     check_element_accessibility(t_game *game); // check_reachable_elem

//Game

void    game_init(t_game **game); //init_game
void    begin_game(t_game *game); //start_game
int    import_image(t_game *game, mlx_image_t **img, char *img_path); // load_image
int     load_game_images(t_game *game); // load images
void    render_image(t_game *game, mlx_image_t *img, int32_t x, int32_t y); // draw_image
void    draw_game(t_game *game); // render_game
void    render_dynamic_elements(t_game *game); // render_dynamic
int    close_game(t_game *game); // exit_game
int     game_won(t_game *game); // win_game
void	dragon_moves_press(struct mlx_key_data keydata, t_game *game); //solo cambia lo de player a dragon 
void	dragon_moves_hold(struct mlx_key_data keydata, t_game *game); //solo cambia lo de player a dragon 
int     validate_dragon_move(t_game *game, int x, int y); // validate_p_move

//free

void	free_game(t_game **game);
void    *freeGameArrOnError(char ***arr, size_t iterator); // *free_game_arr_at_err
void    *release_map_array(char ***map_arr); // *free_map_arr
void	free_mlx(t_game *game);

// utils

void    findElementPosition(t_game *game, char c, t_pos **pos); //get_elem_pos
int     checkWall(t_game *game, int x, int y); // is_wall

//MLX hooks
void    handleKeyPress(struct mlx_key_data keydata, void *param); // key_handler
void    handleCloseEvent(void *param); // close_handler

#endif
