#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>

static const int MAX_PATH_LENGTH=256;

// Utils functions
void	select_print_color(int file_type);
void	list_base_directory(char *base_path);
char	*get_current_directory_path();

# endif
