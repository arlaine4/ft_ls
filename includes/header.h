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
void		look_for_file_in_directory(char *path);
void		handle_no_args();
void		handle_double_args(char *av);
void		handle_triple_args(char *av1, char *av2);
t_options	*get_prog_options(char *s, t_options *options);
// -------------------------------------------------------------- //

// -------------------------------------------------------------- //
//							utils.c								  //
DIR			*get_directory(char *path);
void		select_print_color(char *path, char *name, int type);
void		print_directory_content(char *dir_path, DIR *dir);
char		*get_current_directory_path(char *buff, char *path);
// -------------------------------------------------------------- //

// -------------------------------------------------------------- //
//							list.c								  //
void		fill_list_content(t_file **node, struct dirent *content);
t_file		*init_list_head(struct dirent *entry);
t_file		*add_node_to_list(t_file **prev, struct dirent *content);
// -------------------------------------------------------------- //


#endif
