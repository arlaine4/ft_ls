#include "../includes/header.h"
#include "../ft_printf/includes/ft_printf.h"

void	select_print_color(int file_type)
{
	if (file_type == 8)
		ft_printf("\033[34m");
	else if (file_type == 10)
		ft_printf("\033[36m");
}

void	list_base_directory(char *base_path)
{
	DIR *dir;
	struct dirent *dir_content;

	dir = opendir(base_path);
	while ((dir_content = readdir(dir)) != NULL)
	{
		select_print_color(dir_content->d_type);
		if (dir_content->d_name[0] != '.' && \
				dir_content->d_name[ft_strlen(dir_content->d_name) - 1] != '~')
		{
			ft_printf("%s  ", dir_content->d_name);
			ft_printf("\033[0m");
		}

	}
	ft_printf("\n");
}

char	*get_current_directory_path()
{
	char	*buf;
	char	*ptr;

	if ((buf = (char *)malloc((size_t)MAX_PATH_LENGTH)) != NULL)
		ptr = getcwd(buf, (size_t)MAX_PATH_LENGTH);
	else
		return NULL;
	return ptr;
}
