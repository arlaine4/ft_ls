# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	select_print_color(int file_type, char *file_name, char *path)
{
	/*
		Selecting corect color code for printing file, folder, link, executable
		Probably missing a type or two
	*/
	path = ft_strjoin(path, "/");
	file_name = ft_strjoin(path, file_name);

	if (file_type == 4)
		ft_printf("\033[1;34m");
	else if (file_type == 8)
	{
		if (!(access(file_name, X_OK)))
			ft_printf("\033[32m");
	}
	else if (file_type == 10)
		ft_printf("\033[1;36m");
	free(path);
	free(file_name);
}

void	list_base_directory(char *base_path)
{
	/*
		Looping over the current directory, looking through files one by one
		and printing them with the correct color codes
	*/
	DIR *dir;
	struct dirent *dir_content;

	dir = opendir(base_path);
	while ((dir_content = readdir(dir)) != NULL)
	{
		if (dir_content->d_name[0] != '.' && \
				dir_content->d_name[ft_strlen(dir_content->d_name) - 1] != '~')
		{
			select_print_color(dir_content->d_type, dir_content->d_name, base_path);
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
