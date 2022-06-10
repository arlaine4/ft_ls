# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	select_print_color(char *path, char *name, int type)
{
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, name);
	//ft_printf("%s\t is_exec : %d", path, access(path, X_OK));
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
	if (buff == NULL)
	{
		ft_printf("Error opening directory %s\n", ".");
		return NULL;
	}
	return buff;
}
