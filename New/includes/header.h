#ifndef HEADER_H
# define HEADER_H

# include "../ft_printf/includes/ft_printf.h"

# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>

typedef struct s_node
{
	char		*name;
	//char		*full_path;
	int			type;
	mode_t		mode;
	nlink_t		st_nlink;
	uid_t		st_uid;
	gid_t		st_gid;
	off_t		size;
	dev_t		st_rdev;
	time_t		time;
	long		ntime;

	void		*next;
}				t_node;

// Storing list of paths to execute ls on
typedef struct 	s_path
{
	char			*c_path;
	int				single_file;
	void			*node;
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
void					print_args_debug(t_options *options);
int						check_if_file_is_dir(const char *file_name);
long unsigned int		str_double_len(char **args);
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

//------------------------------ ls.c ------------------------------------------------------//
void	parse_paths(t_path *paths, t_options *options);
void	parse_path_content(t_path **path, t_options *options);
void	init_new_node(t_path **path, struct stat *buf, struct dirent *content);
//------------------------------------------------------------------------------------------//
#endif

