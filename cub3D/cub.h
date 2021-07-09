/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:10:47 by drogue            #+#    #+#             */
/*   Updated: 2021/02/17 02:15:55 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx_mms_20200219/mlx.h"

typedef	struct	s_parametrs
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	int			cel[3];
	int			floor[3];
	int			width;
	int			height;
	char		**map;
}				t_par;

typedef struct	s_tex
{
	void		*img;
	char		*addr;
	int			bp;
	int			ll;
	int			en;
}				t_tex;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bp;
	int			ll;
	int			en;
	t_tex		tex[4];
	t_tex		spr;
}				t_mlx;

typedef struct	s_sprite
{
	float		x;
	float		y;
}				t_sprite;

typedef	struct	s_pos
{
	float		pos_x;
	float		pos_y;

	float		dir_x;
	float		dir_y;

	float		plane_x;
	float		plane_y;

	float		camera_x;

	float		ray_dir_x;
	float		ray_dir_y;

	float		side_dist_x;
	float		side_dist_y;

	float		delta_dist_x;
	float		delta_dist_y;
	float		perp_wall_dist;

	int			map_x;
	int			map_y;

	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;

	int			draw_start;
	int			draw_end;

	float		wall_x;

	int			tex_x;
	int			tex_y;
	float		step;
	float		*buffer;

	float		sprite_x;
	float		sprite_y;

	float		inv_det;

	float		transform_x;
	float		transform_y;

	int			sprite_screen_x;

	int			sprite_height;
	int			sprite_width;

	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;

	int			v_move_screen;
}				t_pos;

typedef struct	s_data {
	t_list		*file;

	int			nwse;
	int			count_sprite;
	int			count_players;
	t_sprite	*sprites;
	float		*sprite_dis;
	int			*sprite_order;
	t_par		par;
	t_mlx		mlx;
	t_pos		pos;
	int			save;
	int			fd;
}				t_data;

typedef struct	s_header {
	uint32_t	size_file;
	uint32_t	reserved;
	uint32_t	pixel_offset;
	uint32_t	size_header;
	int32_t		width;
	int32_t		height;
	uint16_t	number_planes;
	uint16_t	color_depth;
	uint32_t	compression;
	uint32_t	raw_size;
	int32_t		horizontal_res;
	int32_t		vertical_res;
	uint32_t	color_entries;
	uint32_t	important_col;
}				t_header;

int				main(int argc, char **argv);
void			par_init(t_data *data);
int				file_processing(t_data *data, int argc, char **argv);
void			main_rendering(t_data *data, t_pos *pos);
int				reading_key(int key, t_data *data);

void			error_processing(int i, t_data *data);

int				check_arguments(t_data *data, int argc, char **argv);
int				check_file(t_data *data, char *str);

int				filling_list(t_list **file, t_data *data);
int				add_elem_list(t_list **file, char *linep);
t_list			*ft_lstnew_2(void *content);

int				reading_parameters_map(t_data *data);
int				filling_parameters(char **s, t_data *data);
int				reading_map(t_list *file, t_par *par);
int				reading_size_map(t_list *file);

int				my_atoi(const char *str);

int				reading_colors(char **s, int *color);
int				check_comma(char **s);
int				read_resolution(char **s, t_data *data);
int				read_textur(char **s, char **textur);
void			skip_space(char **s);

int				checking_parameters(t_data *data);

int				checking_side_map(t_par par);
int				check_top_bottom(char **map, int i);

int				checking_valid_map(t_data *data, t_par par);
int				cheking_value_cell(t_data *data, t_par par, int i, int j);
int				verify_zero_player(t_data *data, char **pi, int j, int i);
int				verify_zero(char **pi, int j, int i);

int				init_mlx(t_mlx *mlx, t_data data);

void			initialization_pos(t_data *data);
void			init_w(t_data *data);
void			init_e(t_data *data);
void			init_s(t_data *data);
void			init_n(t_data *data);

int				read_sprites(t_data *data, t_par par);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				background_rendering(t_data *data);

void			initialization_ren(t_data *data, t_pos *pos, int i);
void			initialization_step(t_pos *pos);

void			search_border(t_pos *pos, t_data *data);
void			calculate_param(t_pos *pos, t_data *data);

void			print_wall(t_pos *pos, t_data *data, int i);

void			sp_order_dis(t_data *data, t_pos *pos);
void			sort_sprite(t_data *data, t_pos *pos);
void			calculate_drow_sp(t_data *data, t_pos *pos);
void			calculate_par_sp(t_data *data, t_pos *pos, int i);
void			sprites_processing(t_data *data, t_pos *pos);

void			print_sprites(t_pos *pos, t_data *data);
void			draw_column(char *addr, char *addr_img, t_data *data);

void			rotate_l(t_data *data);
void			rotate_r(t_data *data);
int				exit_game(t_data *data);

void			move_forward(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

void			init_header(t_data *data, t_header *header);
int				write_img(int fd, t_data *data, t_mlx mlx);
int				filling_header(int fd, t_header header);
int				screenshot(t_data *data);

#endif
