# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	select_print_color(char *path, char *name, int type)
{
	// Joining directory path with file name in order to check the right to run
	// the executable if type == 8
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, name);
	if (type == 4)
		ft_printf("\033[1;34m");
	else if (type == 8)
	{
		if (!(access(path, X_OK)))
			ft_printf("\033[1;32m");
	}
	else if (type == 10)
		ft_printf("\033[36m");
}

char	*get_directory_path(char *buff, char *path)
{
	if (ft_strcmp(path, ".") == 0)
		buff = getcwd(buff, 256);
	// add condition if we do have path as a parameter so we don't use getcwd
	// but opendir or something like that instead
	if (buff == NULL)
	{
		ft_printf("Error opening directory %s\n", ".");
		return NULL;
	}
	return buff;
}
