#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>

# include <sys/stat.h>

static const int MAX_PATH_LENGTH=256;

typedef struct	s_options
{
	int	l;
	int	a;
	int	r;
	int R;
	int	t;
	int	invalid;
}				t_options;

void		select_print_color(int file_type, char *file_name, char *path);
void		list_base_directory(char *base_path, t_options *options);
int			check_dash_in_argv(char *arg);
char		*get_current_directory_path();
DIR			*get_directory_path(char *path);
t_options	*check_and_re_order_args(char *args);

# endif
