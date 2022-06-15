#ifndef HEADER_H
# define HEADER_H

# include "../ft_printf/includes/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>

typedef struct	s_options
{
	int	l;
	int	r;
	int	R;
	int	a;
	int	t;
}				t_options;

//------------------------------ utils.c ----------------------------//
void	print_args_debug(char *path, t_options *options);
//-------------------------------------------------------------------//

//----------------------------- parsing.c ---------------------------//
void	loop_over_argv(t_options **options, char *arg);
char	*parse_single_arg(t_options **options, char *path, char *arg);
//-------------------------------------------------------------------//


#endif

