#ifndef HEADER_H
# define HEADER_H

# include "../ft_printf/includes/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>

// Storing list of paths to execute ls on
typedef struct 	s_path
{
	char			*c_path;
	int				single_file;
	void			*next;
}				t_path;

// Storing ls arguments : -l -R -r -t -a -> -lRrat
typedef struct	s_options
{
	int		l;
	int		r;
	int		R;
	int		a;
	int		t;
}				t_options;

//------------------------------ utils.c ----------------------------------------------------//
void	print_args_debug(char *path, t_options *options);
int		check_if_file_is_dir(const char *file_name);
int		str_double_len(char **args);
//------------------------------------------------------------------------------------------//

//----------------------------- parsing.c --------------------------------------------------//
void	loop_over_argv(t_options **options, char *arg);
t_path	*parse_single_arg(t_options **options, char *path, char *arg);
t_path	*parse_multiple_args(t_options **options, char *path, char **args);
//------------------------------------------------------------------------------------------//

//------------------------------- list.c ---------------------------------------------------//
void	init_path_node(t_path **path_node, char *path, char *add_to_path);
void	print_paths_list(t_path *paths);
t_path	*add_node_to_paths(t_path **prev, t_path *new_path);
//------------------------------------------------------------------------------------------//

#endif

