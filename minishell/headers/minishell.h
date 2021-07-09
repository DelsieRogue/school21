/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:25:32 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 15:08:24 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <fcntl.h>
# include <unistd.h>
# include <term.h>
# include <stdio.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "../libs/libft/libft.h"
# include <curses.h>
# include <term.h>
# include "../libs/gnl/get_next_line.h"
# include <sys/types.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include "util.h"
# include <limits.h>

typedef struct		s_tuple
{
	char			*key;
	char			*value;
}					t_tuple;

typedef struct		s_env
{
	struct s_tuple	*env;
	struct s_env	*next;
}					t_env;

typedef struct		s_his
{
	char			**his;
	char			*tmp_his;
	int				check;
	int				i_his;
}					t_his;

typedef struct		s_read
{
	char			*str;
	int				i;
	int				index;
	t_his			his;
}					t_read;

typedef struct		s_pars
{
	char			**arg;
	int				i;
	int				n;
	t_his			*his;
}					t_pars;

typedef struct		s_data
{
	char			**mas;
	int				save_fd_1;
	int				save_fd_0;
	int				rr;
	int				lr;
	int				fd[2];
	int				pipe;
	pid_t			pid[1024];
	int				i_pid;
}					t_data;

t_env				*g_list_env;

int					free_in_mas(char **mas);
char				*my_strjoin(char *s1, char *s2);
int					free_two_mas(char ***mas, int n);
int					ft_strlen_mas(char **s);
int					add_new_str(char *s, char ***mas);

void				free_str(char **s);
int					ft_putchar(int c);
int					add_str(char **str2, char *str);
int					term_on(void);
int					term_off(void);

int					my_strlen(char *s);
char				*char_add(char *str, char c);
char				**p_add(char **mas);
int					char_join(t_pars *pars, char c);
int					p_join(t_pars *pars, char *str);

void				error(char *s, int *ex);
int					check_name(t_data *arg, t_pars *pars, int i, int *ex);
void				error_pipe(t_data *arg, t_pars *pars, int *ex, int j);

void				signal_c(int a);
void				signal_q(int a);
int					call_execve(t_data *arg, char *s, int *ex);
int					check_path(char *path);
int					proc_execve(t_data *arg, int *ex);

int					my_num_exit(char *s);
int					my_exit(char **mas, int *ex, t_his *his);

void				init_arg(t_data *arg);
int					call_functions(t_data *arg, int *ex, t_his *his);
int					check_simvols(t_data *arg, t_pars *pars, int i, int *ex);
void				loop_processing(t_data *arg, t_pars *pars, int *ex);
int					array_processing(t_pars *pars, int *ex);

int					child_process(t_data *arg, int *ex, t_his *his, int op);
int					parent_process(t_data *arg);
int					pipe_proc(t_data *arg, int *ex, t_his *his, int op);
void				all_wait(int *ex, int pipe, t_pars *pars, t_data *arg);
int					check_pipe(t_pars *pars);

void				back_redirect(t_data *arg);
void				apply_red(t_data *arg);
int					right_redirect(t_data *arg, t_pars *pars, int i, int *ex);
int					two_right_redirect(t_data *arg, t_pars *pars, int i,\
					int *ex);
int					left_redirect(t_data *arg, t_pars *pars, int i, int *ex);

void				change_pwd(void);
char				*strjoin_cd(char const *s1, char const *s2, int clear_s1);
void				set_old_pwd(void);
void				set_env_pwd(void);
int					cd(const char *path);
int					my_echo(char **params);

size_t				list_size(t_env *list);
char				*get_value(const char *value);
char				*get_key(const char *key);
t_env				*add_list_env(void *key, void *value);
void				get_list_env(void);
char				*find_env_value(const char *key);
void				add_environ(const char *key, const char *value);
int					unset_del_item(t_env *tmp, t_env *prev, char *key);
int					unset(char **keys);
void				sort_env(t_env **env, size_t size);
void				print_env(void);
void				print_sorted_envs(t_env *list);
char				**list_to_arr(t_env *env);
t_env				*search_key(const char *key);
void				add_export(char *s);
void				export(char **args, int *ex);

void				press_backspace(t_read *g_s);
void				press_enter(t_read *g_s, int *ex);

void				press_up(t_read *g_s, t_his *his);
void				press_down(t_read *g_s, t_his *his);

void				press_left(t_read *g_s);
void				press_right(t_read *g_s);

void				iter(t_read *g_s);
int					check_simvol(t_read *g_s, char *buf, int *ex);
int					check_signal(t_read *g_s, char *buf, int *ex);

int					parse_doll(t_pars *pars, char *pi, int *ex);
int					read_env(t_pars	*pars, char *s, int *ex);

int					read_shield(t_pars *pars, char *s);
int					read_shield_2(t_pars *pars, char *s);
int					read_two_quot(t_pars *pars, char *s, int *ex);
int					read_one_quot(t_pars *pars, char *s);

int					check_begin(t_pars *pars, char *s, int *ex, char c);
void				add_spec(t_pars *pars, char *s, int *ex);
int					semicolon(t_pars *pars, char *s, int *ex);

int					parse_string(t_pars *pars, char *s, int *ex);
void				init_pars(t_pars *pars, t_his *his);
int					proccecing_string(char *str, int *ex, t_his *his);

int					his_add(char ***mas, char *line);
int					set_history(t_his *his);
int					get_history(t_his *his);

char				*get_pwd(void);
int					print_pwd(void);

#endif
