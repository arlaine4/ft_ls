# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	handle_no_args()
{
	//t_file	*head = NULL;
	char	*dir_path;
	DIR		*dir;
	char	buff[256];
	struct	dirent *entry;

	dir_path = get_directory_path(buff, ".");
	dir = opendir(dir_path);
	//entry = readdir(dir);
	//head = init_list_head(entry);
	//ft_printf("head_name : %s\thead_type : %d\n", head->name, head->type);

	if (dir == NULL)
		ft_printf("Can't open current folder for some reason.\n");
	else
	{
		while ((entry = readdir(dir)) != NULL)
		{
			select_print_color(dir_path, entry->d_name, entry->d_type);
			//ft_printf("%s  \033[0m%d", entry->d_name, entry->d_type);
			if (entry->d_name[0] != '.')
				ft_printf("%s  \033[0m", entry->d_name);
		}
		ft_printf("\n");
	}
}

