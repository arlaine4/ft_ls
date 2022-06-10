#ifndef HEADER_H
# define HEADER_H

# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/libft/libft.h"


// struct handleing ft_ls arguments such as -l -a -R -r -t -> -lRrat
typedef struct s_options
{
	int	a;
	int	r;
	int	R;
	int	t;
	int	l;
	int	invalid;
}				t_options;

// struct containing informations about each of parsed using readdir, also
// containing pointer to next file descriptor since we are using a linked list
typedef struct 	s_file
{
	char			*name;
	int				type;
	struct s_file	*next;
}				t_file;


// -------------------------------------------------------------- //
//							Parsing.c							  //
void	handle_no_args();
// -------------------------------------------------------------- //

// -------------------------------------------------------------- //
//							utils.c								  //
void	select_print_color(char *path, char *name, int type);
char	*get_directory_path(char *buff, char *path);
// -------------------------------------------------------------- //

// -------------------------------------------------------------- //
//							list.c								  //
t_file	*init_list_head(struct dirent *entry);
// -------------------------------------------------------------- //


#endif
